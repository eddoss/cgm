#pragma once


#include <cstdint>
#include <Global.hpp>
#include <OpenGL/BaseObject.hpp>
#include <memory>


/**
 * OpenGL vertex buffer object.
 */
class VBO : OpenGLObject
{
    CGM_EXAMPLES_DISABLE_COPY(VBO)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using Shared    = std::shared_ptr<VBO>;
    using Unique    = std::unique_ptr<VBO>;
    using Weak      = std::weak_ptr<VBO>;

/* ####################################################################################### */
public: /* Enums */
/* ####################################################################################### */

    /**
     * Buffer types.
     */
    enum EBufferType
    {
        ArrayBuffer             = GL_ARRAY_BUFFER,
        IndexBuffer             = GL_ELEMENT_ARRAY_BUFFER,
        PixelPackBuffer         = GL_PIXEL_PACK_BUFFER,
        PixelUnpackBuffer       = GL_PIXEL_UNPACK_BUFFER
    };

    /**
     * Buffer usage patterns.
     */
    enum EUsagePattern
    {
        StreamDraw              = GL_STREAM_DRAW,
        StreamRead              = GL_STREAM_READ,
        StreamCopy              = GL_STREAM_COPY,
        StaticDraw              = GL_STATIC_DRAW,
        StaticRead              = GL_STATIC_READ,
        StaticCopy              = GL_STATIC_COPY,
        DynamicDraw             = GL_DYNAMIC_DRAW,
        DynamicRead             = GL_DYNAMIC_READ,
        DynamicCopy             = GL_DYNAMIC_COPY
    };

    /**
     * Buffer access patterns.
     */
    enum EAccessPattern
    {
        ReadOnly                = GL_READ_ONLY,
        WriteOnly               = GL_WRITE_ONLY,
        ReadWrite               = GL_READ_WRITE
    };

    /**
     * Buffer access flags
     */
    enum ERangeAccessFlag
    {
        RangeRead               = GL_MAP_READ_BIT,
        RangeWrite              = GL_MAP_WRITE_BIT,
        RangeInvalidate         = GL_MAP_INVALIDATE_RANGE_BIT,
        RangeInvalidateBuffer   = GL_MAP_INVALIDATE_BUFFER_BIT,
        RangeFlushExplicit      = GL_MAP_FLUSH_EXPLICIT_BIT,
        RangeUnsynchronized     = GL_MAP_UNSYNCHRONIZED_BIT
    };

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Setup requaired parameters.
     * @param bufferType Type of this VBO.
     * @param usagePattern Usage pattern of  this VBO.
     * @param accessPattern Acces pattern of this VBO.
     */
    VBO(EBufferType bufferType, EUsagePattern usagePattern, EAccessPattern accessPattern);

    /**
     * Destructor.
     */
   ~VBO() override;

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * Get buffer type.
     */
    EBufferType
    bufferType() const;

    /**
     * Get usage pattern.
     */
    EUsagePattern
    usagePattern() const;

    /**
     * Get access pattern.
     */
    EAccessPattern
    accessPattern() const;

    /**
     * Check whether buffer is readable.
     */
    bool
    readable() const;

    /**
     * Get buffer size (in bytes).
     */
    int32_t
    size() const;

/* ####################################################################################### */
public: /* Methods: IO */
/* ####################################################################################### */

    /**
     * Read any bytes from buffer.
     * @param[in] from Start byte position offset.
     * @param[in] count How much need to read.
     * @param[out] outData output data buffer.
     */
    bool
    read(uint32_t from, uint32_t count, void* outData) const;

    /**
     * Write any bytes to buffer.
     * @param from Start byte position offset.
     * @param count How much need to write.
     * @param outData Input data to write.
     */
    bool
    write(uint32_t from, uint32_t count, const void* data);

    /**
     * Allocate memory for buffer on GPU.
     * @param count How much bytes need to allocate.
     * @param data Input data to write in allocated memory.
     */
    void
    allocate(uint32_t count, const void* data);

/* ####################################################################################### */
public: /* GL object interface */
/* ####################################################################################### */

    /**
     * Bind this object.
     * @return true if binding was succeded, false otherwise.
     */
    bool
    bind() const override;

    /**
     * Release this object.
     * @return true if releasing was succeded, false otherwise.
     */
    bool
    release() const override;

    /**
     * Create this object.
     * @return true if was created, false otherwise.
     */
    bool
    create() override;

    /**
     * Destroy this object.
     * @return true if was destroyed, false otherwise.
     */
    void
    destroy() override;

/* ####################################################################################### */
public: /* Private members */
/* ####################################################################################### */

    EBufferType
    m_bufferType;

    EUsagePattern
    m_usagePattern;

    EAccessPattern
    m_accessPattern;
};