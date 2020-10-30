

#include <Rendering/LinePainter.hpp>
#include <GL/glew.h>


void
LinePainter::render(const Geometry& geo, const Camera& camera)
{
    auto mat = geo.material();
    mat->bind();
    mat->setUniform("matXform", geo.xform);
    mat->setUniform("matWorldToCamera", camera.inverseSpace());
    mat->setUniform("matCameraToProject", camera.ndc());

    geo.vao().bind();
    glDrawElements(GL_LINES, GLsizei(geo.indicesCount()), GL_UNSIGNED_INT, nullptr);
    geo.vao().release();
}