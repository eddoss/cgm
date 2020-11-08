

#include <Rendering/TextPainter.hpp>


void
TextPainter::render(const Text& text, const Camera& camera)
{
//    auto mat = text.material();
//    mat->bind();
//    mat->setUniform("matWorldToCamera", camera.controller->inverseSpace());
//    mat->setUniform("matCameraToProject", camera.model->projection());
//
//    text.vao().bind();
////    glDrawArrays(GL_TRIANGLE_FAN, 0, text.roughPointsCount());
//    glDrawArrays(GL_POINTS, 0, text.roughPointsCount());
////    std::cout << count << ", ";
////    glDrawElements(GL_TRIANGLE_FAN, 23, EGLType::UInt, nullptr);
//    text.vao().release();
}