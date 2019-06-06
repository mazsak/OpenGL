//
// Created by Mateusz on 23.05.2019.
//

#include "Object.h"


void Object::update(glm::vec3 positionCamera, glm::vec3 directionCamera) {

    float distance = glm::distance(positionCamera, glm::vec3(getAbsolutePosition()[3].x, getAbsolutePosition()[3].y, getAbsolutePosition()[3].z));
    float size = glm::distance(getScale()*model->getMax(), getScale()*model->getMin());

    float show = distance-size;

//    setVisible(show <= 30);

    if(isVisible()){
        for (int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->update(positionCamera, directionCamera);
        }
    }
}

void Object::render(Shader * shader) {
    Object::animate();
    if (Object::isVisible()) {
        model->drawModel(shader);
        glUniformMatrix4fv(shader->getModelMatrixId(), 1, GL_FALSE, &Object::getAbsolutePosition()[0][0]);

        for(int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->render(shader);
        }
    }
}


void Object::animate() {
    Node::animate();

    double currentTime = glfwGetTime();
    deltaTime = float(currentTime - lastFrame);

//    if(deltaTime > 0.5) {
        for (int i = 0; i < animations.size(); ++i) {
            Frame frame = animations[i]->animate();
//            printf(" x= %f y= %f, z= %f\n", frame.translation.x, frame.translation.y, frame.translation.z);

            setTranslation(frame.translation);
            setRotation(frame.rotation);
            setScale(frame.scale);
            updateAbsolutePosition();
        }

        lastFrame = currentTime;
//    }
}

Object::Object(unsigned int id, Node *parent, Model *model) : Node(id, parent), model(model) {

}

void Object::addAnimation(Animation *animation) {
    animations.emplace_back(animation);
}
