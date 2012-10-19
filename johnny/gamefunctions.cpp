MapBlock myBlocks[3] =
    {MapBlock(0.0, 0.0, 0.0, 2.0, 2.0, 2.0),
     MapBlock(-5.0, -5.0, -5.0, 1.0, 1.0, 1.0),
     MapBlock(3.0, 5.0, -9.0, 3.0, 1.0, 2.0)
    };

float totalTime = 0;

void gameInit() {
}

void gameUpdate(float dt) {
    totalTime += dt;
}

void gameDraw() {
    glLoadIdentity();
    gluLookAt(10.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    std::cout << "Drawing at time " << totalTime << std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(totalTime*30, 0.0, 1.0, 0.0);
    
    for (int i=0; i<3; i++) {
        myBlocks[i].draw();
    }
}
