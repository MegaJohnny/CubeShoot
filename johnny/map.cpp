class MapBlock {
    public:
        MapBlock(float _x, float _y, float _z, float _xs, float _ys, float _zs);
        void draw();
    private:
        float x, y, z;
        float xs, ys, zs;
};

MapBlock::MapBlock(float _x, float _y, float _z,
                   float _xs, float _ys, float _zs) {
    x = _x;
    y = _y;
    z = _z;

    xs = _xs;
    ys = _ys;
    zs = _zs;
}

void MapBlock::draw() {
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_STRIP);
    //"front" face
    glVertex3f(x,    y,    z);
    glVertex3f(x+xs, y,    z);
    glVertex3f(x,    y+ys, z);
    glVertex3f(x+xs, y+ys, z);
    //top face
    glVertex3f(x,    y+ys, z+zs);
    glVertex3f(x+xs, y+ys, z+zs);
    //back face
    glVertex3f(x,    y,    z+zs);
    glVertex3f(x+xs, y,    z+zs);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    //left face
    glVertex3f(x+xs, y+ys, z);
    glVertex3f(x+xs, y+ys, z+zs);
    glVertex3f(x+xs, y,    z);
    glVertex3f(x+xs, y,    z+zs);
    //bottom face
    glVertex3f(x,    y,    z);
    glVertex3f(x,    y,    z+zs);
    //right face
    glVertex3f(x,    y+ys, z);
    glVertex3f(x,    y+ys, z+zs);
    glEnd();
}
