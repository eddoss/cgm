

#include <Rendering/PolyPainter.hpp>


void
PolyPainter::render(const Geometry& geo, const Camera& camera)
{
    auto mat = geo.material();
    mat->bind();
    mat->setUniform("matXform", geo.xform);
    mat->setUniform("matWorldToCamera", camera.controller->inverseSpace());
    mat->setUniform("matCameraToProject", camera.model->projection());

    geo.vao().bind();
//    glDrawArrays(GL_TRIANGLE_FAN, 0, GLsizei(geo.pointsCount()));
    glDrawElements(GL_TRIANGLE_FAN, GLsizei(geo.indicesCount()), EGLType::UInt, nullptr);
    geo.vao().release();
}