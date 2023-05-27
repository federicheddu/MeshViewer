#include <cinolib/meshes/meshes.h>
#include <cinolib/gl/surface_mesh_controls.h>
#include <cinolib/gl/volume_mesh_controls.h>

using namespace cinolib;

int main(int argc, char** argv) {

    if(argc != 3) return 1;

    GLcanvas gui;
    MeshType type;
    std::string param(argv[1]);

    if(param == "-tri")
        type = TRIMESH;
    else if(param == "-quad")
        type = QUADMESH;
    else if(param == "-pgon")
        type = POLYGONMESH;
    else if(param == "-tet")
        type = TETMESH;
    else if(param == "-hex")
        type = HEXMESH;
    else if(param == "-phed")
        type = POLYHEDRALMESH;
    else return 2;

    DrawableTrimesh<> tri;
    DrawableQuadmesh<> quad;
    DrawablePolygonmesh<> pgon;
    DrawableTetmesh<> tet;
    DrawableHexmesh<> hex;
    DrawablePolyhedralmesh<> phed;

    switch (type) {
        case TRIMESH:
            tri.load(argv[2]);
            tri.updateGL();
            gui.push(&tri);
            gui.push(new SurfaceMeshControls<DrawableTrimesh<>>(&tri, &gui));
            break;
        case QUADMESH:
            quad.load(argv[2]);
            quad.updateGL();
            gui.push(&quad);
            gui.push(new SurfaceMeshControls<DrawableQuadmesh<>>(&quad, &gui));
            break;
        case POLYGONMESH:
            pgon.load(argv[2]);
            pgon.updateGL();
            gui.push(&pgon);
            gui.push(new SurfaceMeshControls<DrawablePolygonmesh<>>(&pgon, &gui));
            break;
        case TETMESH:
            tet.load(argv[2]);
            tet.updateGL();
            gui.push(&tet);
            gui.push(new VolumeMeshControls<DrawableTetmesh<>>(&tet, &gui));
            break;
        case HEXMESH:
            hex.load(argv[2]);
            hex.updateGL();
            gui.push(&hex);
            gui.push(new VolumeMeshControls<DrawableHexmesh<>>(&hex, &gui));
            break;
        case POLYHEDRALMESH:
            phed.load(argv[2]);
            phed.updateGL();
            gui.push(&phed);
            gui.push(new VolumeMeshControls<DrawablePolyhedralmesh<>>(&phed, &gui));
            break;
    }

    return gui.launch();
}