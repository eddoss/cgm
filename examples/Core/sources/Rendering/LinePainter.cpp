

#include <Rendering/LinePainter.hpp>
#include <GL/glew.h>


void
LinePainter::render(const Geometry& geo, const Camera& camera)
{
    geo.material()->bind();
    geo.material()->setUniform("xform", geo.xform);
    geo.material()->setUniform("cameraSpace", camera.inverseSpace());
    geo.material()->setUniform("cameraProjection", camera.ndc());

    geo.vao().bind();
    glDrawElements(GL_LINES, GLsizei(geo.indicesCount()), GL_UNSIGNED_INT, nullptr);
    geo.vao().release();
}