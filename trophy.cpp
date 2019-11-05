#include "trophy.h"
#include "trianglesurface.h"

Trophy::Trophy()
{
    Vertex v{};
    //Bottom
    v.set_xyz(-0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Top
    v.set_xyz(-0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Front
    v.set_xyz(-0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Back
    v.set_xyz(0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.-2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Left
    v.set_xyz(-0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(-0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Right
    v.set_xyz(0.2,0,-0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.2,0.4,0.2); v.set_rgb(1,0,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0,-0.2); v.set_rgb(1,0,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.2,0.4,-0.2); v.set_rgb(1,0,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Trophy part
    // Top
    v.set_xyz(-0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.1,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,-0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Front
    v.set_xyz(-0.1,0.4,-0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,-0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.4,-0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.4,-0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Back
    v.set_xyz(0.1,0.4,0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.4,0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.-2,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.4,0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Left
    v.set_xyz(-0.1,0.4,0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,-0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.4,-0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(-0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.4,0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(-0.1,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    // Right
    v.set_xyz(0.1,0.4,-0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.4,0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);

    v.set_xyz(0.1,0.8,0.1); v.set_rgb(0,1,0); v.set_uv(0,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.4,-0.1); v.set_rgb(0,1,0);  v.set_uv(1,0);
    mVertices.push_back(v);
    v.set_xyz(0.1,0.8,-0.1); v.set_rgb(0,1,0); v.set_uv(1,1);
    mVertices.push_back(v);
}

//void Trophy::OnOverlapEvent(VisualObject *object)
//{
//    if (object->name() == "Octahedronball")
//    {
//        Pawn *pawn = static_cast<Pawn *>(object);
//        pawn->incTrophies();
//        this->destroy();
//    }
//}
