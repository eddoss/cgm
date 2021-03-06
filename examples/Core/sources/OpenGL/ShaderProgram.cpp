#include <Global.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <filesystem>
#include <streambuf>
#include <iostream>
#include <fstream>
#include <string>


/* ####################################################################################### */
/* Support implementation macro */
/* ####################################################################################### */

#ifndef IMPL_SUPPORT_SET_UNIFORM_COMMON
    #define IMPL_SUPPORT_SET_UNIFORM_COMMON                                                     \
    GLint location = glGetUniformLocation(m_id, name.data());                                   \
    if (location == -1)                                                                         \
    {                                                                                           \
        CGM_EXAMPLES_FUNC_ERROR(std::string("could not set uniform value: '") + name + "'");    \
        return;                                                                                 \
    }
#endif

/* ####################################################################################### */
/* Static methods */
/* ####################################################################################### */

std::wstring
ShaderProgram::getShaderFileExtensionByType(ShaderProgram::EShaderType shaderType)
{
    switch (shaderType)
    {
        case ShaderProgram::EShaderType::Vertex:                    return L".vert";
        case ShaderProgram::EShaderType::TessellationControl:       return L".tesc";
        case ShaderProgram::EShaderType::TessellationEvaluation:    return L".tese";
        case ShaderProgram::EShaderType::Geometry:                  return L".geom";
        case ShaderProgram::EShaderType::Fragment:                  return L".frag";
        default:                                                    return L".comp";
    }
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::getShaderTypeByFile(const std::wstring& file)
{
    std::wstring ext = std::filesystem::path(file).extension().wstring();

    if (ext == L".vert") return ShaderProgram::EShaderType::Vertex;
    if (ext == L".tesc") return ShaderProgram::EShaderType::TessellationControl;
    if (ext == L".tese") return ShaderProgram::EShaderType::TessellationEvaluation;
    if (ext == L".geom") return ShaderProgram::EShaderType::Geometry;
    if (ext == L".frag") return ShaderProgram::EShaderType::Fragment;
    if (ext == L".comp") return ShaderProgram::EShaderType::Compute;

    return -1;
}

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

ShaderProgram::~ShaderProgram()
{
    if( m_objectCreated )
    {
        glDeleteProgram(m_id);
        glUseProgram(0);
    }
}

/* --------------------------------------------------------------------------------------- */

ShaderProgram::ShaderProgram()
    :OpenGLObject()
{

}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

bool
ShaderProgram::link()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created");
        return false;
    }

    GLint success;

    for(auto m_shadersID : m_shadersIDs)
    {
        glAttachShader(m_id, m_shadersID);
    }

    glLinkProgram( m_id );
    glGetProgramiv( m_id, GL_LINK_STATUS, &success );

    if( !success )
    {
        GLint logLength;
        glGetShaderiv( m_id, GL_INFO_LOG_LENGTH, &logLength );

        if( logLength > 0 )
        {
            char* logData = new char[cgm::u64(logLength)];

            glGetShaderInfoLog(m_id, logLength, nullptr, logData);
            CGM_EXAMPLES_FUNC_INFO(std::string(logData));
        }

        m_linked = false;
        return false;
    }

    for(auto m_shadersID : m_shadersIDs)
    {
        glDeleteShader(m_shadersID);
    }

    m_shadersIDs.clear();

    m_linked = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::linked()
{
    return m_linked;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShader(ShaderProgram::EShaderType shaderType, const std::string& sourceCode)
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created. Create shader program before shader attaching");
        return false;
    }

    const char* source = sourceCode.data();
    GLint       success;
    GLuint      shaderId;

    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &source, nullptr);
    glCompileShader(shaderId);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

    if( !success )
    {
        GLint logLength;
        glGetShaderiv( shaderId, GL_INFO_LOG_LENGTH, &logLength );

        if( logLength > 0 )
        {
            char* logData = new char[cgm::u64(logLength)];

            glGetShaderInfoLog(shaderId, logLength, nullptr, logData);
            CGM_EXAMPLES_FUNC_INFO(std::string(logData));
        }
        return false;
    }
    m_shadersIDs.push_back(shaderId);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShaderFromFile(ShaderProgram::EShaderType shaderType, const std::wstring& file)
{
    std::ifstream stream((std::filesystem::path(file)));
    std::string sourceCode((std::istreambuf_iterator<char>(stream)),std::istreambuf_iterator<char>());
    if (sourceCode.empty()) {return false;}
    addShader(shaderType, sourceCode);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShaderPack(const std::wstring& directory)
{
    auto absdir = std::filesystem::absolute(directory);

    for (const auto& it : std::filesystem::directory_iterator(absdir))
    {
        if (!std::filesystem::is_regular_file(it.path())) continue;
        int type = getShaderTypeByFile(it.path().wstring());
        if (type == -1) continue;
        addShaderFromFile(ShaderProgram::EShaderType(type), it.path().wstring());
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::attributeLocation(const std::string& name) const
{
    return glGetAttribLocation(m_id, name.data());
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::uniformLocation(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created");
        return -1;
    }
    return glGetUniformLocation(m_id, name.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::enableAttributeArray(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created");
        return;
    }

    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_ERROR(std::string("can not enable attribute array: '") + name + "'");
        return;
    }
    glEnableVertexAttribArray(GLuint(location));
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::disableAttributeArray(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created");
        return;
    }
    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_ERROR(std::string("can not disable attribute array: '") + name + "'");
        return;
    }
    glDisableVertexAttribArray(GLuint(location));
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setAttributeBuffer(const std::string& name, EGLType type, cgm::u32 componentCount, cgm::u32 offset, cgm::u32 stride) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is not created");
        return;
    }

    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_ERROR(std::string("could not set attribute array: '") + name + "'");
        return;
    }

    glVertexAttribPointer(GLuint(location), GLint(componentCount), type, GL_TRUE, GLsizei(stride), reinterpret_cast<void*>(offset));
}

/* ####################################################################################### */
/* Uniform variables setters: scalar */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, cgm::i32 scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1i(location, scalar);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::u32 scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1ui(location, scalar);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::f32 scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1f(location, scalar);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, cgm::i32 x, cgm::i32 y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2i(location, x, y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::u32 x, cgm::u32 y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2ui(location, x, y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::f32 x, cgm::f32 y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2f(location, x, y);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y, z */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, cgm::i32 x, cgm::i32 y, cgm::i32 z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3i(location, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::u32 x, cgm::u32 y, cgm::u32 z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3ui(location, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::f32 x, cgm::f32 y, cgm::f32 z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3f(location, x, y, z);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y, z, w */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, cgm::i32 x, cgm::i32 y, cgm::i32 z, cgm::i32 w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4i(location, x, y, z, w);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::u32 x, cgm::u32 y, cgm::u32 z, cgm::u32 w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4ui(location, x, y, z, w);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::f32 x, cgm::f32 y, cgm::f32 z, cgm::f32 w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, x, y, z, w);
}

/* ####################################################################################### */
/* Uniform variables setters: array */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::i32* values, cgm::u32 count, cgm::u32 componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1iv(location, GLsizei(count), values); return;}
    if (componentsCount == 2) {glUniform2iv(location, GLsizei(count), values); return;}
    if (componentsCount == 3) {glUniform3iv(location, GLsizei(count), values); return;}
    if (componentsCount == 4) {glUniform4iv(location, GLsizei(count), values); return;}
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::u32* values, cgm::u32 count, cgm::u32 componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 2) {glUniform2uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 3) {glUniform3uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 4) {glUniform4uiv(location, GLsizei(count), values); return;}
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::f32* values, cgm::u32 count, cgm::u32 componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 2) {glUniform2fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 3) {glUniform3fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 4) {glUniform4fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
}

/* ####################################################################################### */
/* Uniform variables setters: float vectors */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec2& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2f(location, vector.x, vector.y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec3& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3f(location, vector.x, vector.y, vector.z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec4& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

/* ####################################################################################### */
/* Uniform variables setters: angles, matrices and quaternon */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::quat& quaternion) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, quaternion.scalar, quaternion.vector.x, quaternion.vector.y, quaternion.vector.z);
}

/* ####################################################################################### */
/* Uniform variables setters: angles, matrices and quaternon */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat2& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix2fv(location, 1, GL_FALSE, matrix.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat3& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix3fv(location, 1, GL_FALSE, matrix.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat4& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix4fv(location, 1, GL_FALSE, matrix.data());
}

/* ####################################################################################### */
/* GL object interface */
/* ####################################################################################### */

bool
ShaderProgram::bind() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("can not bind shader program, it is not created");
        return false;
    }
    glUseProgram(m_id);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::release() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_WARNING("can not release shader program, it is not created");
        return false;
    }
    glUseProgram(0);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::create()
{
    if( m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_ERROR("shader program is already created");
        return false;
    }

    m_id = glCreateProgram();

    if( m_id == 0 )
    {
        CGM_EXAMPLES_FUNC_ERROR("can not to create shader program");
        m_objectCreated = false;
        return false;
    }

    m_objectCreated = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::destroy()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Warrning: can not destroy shader program, it is not created");
        return;
    }
    glDeleteProgram(m_id);
    glUseProgram(0);

    m_objectCreated = false;
    m_linked = false;
}