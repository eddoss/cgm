

#include <Rendering/DotPainter.hpp>
#include <GL/glew.h>


void
DotPainter::render(const Geometry& geo, const Camera& camera)
{
    auto mat = geo.material();
    mat->bind();
    mat->setUniform("matXform", geo.xform);
    mat->setUniform("matWorldToCamera", camera.controller->inverseSpace());
    mat->setUniform("matCameraToProject", camera.model->projection());

    geo.vao().bind();
    glDrawArrays(GL_POINTS, 0, GLsizei(geo.pointsCount()));
    geo.vao().release();
}