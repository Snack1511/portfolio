#include "mesh.h"

CMesh::CMesh() {
	verts = NULL;
	tris = NULL;
	norms = NULL;
}

CMesh::~CMesh() {
	if (verts) delete[] verts;
	if (tris) delete[] tris;
	if (norms) delete[] norms;
}

void CMesh::computeNormals() {
	for (int i = 0; i < nF; i++) {

		// current face = tris[i]
		// three vertices : tris[i].v0, v1, v2
		int v0 = tris[i].v0;
		int v1 = tris[i].v1;
		int v2 = tris[i].v2;
		vertex normal = computeNormal(verts[v0], verts[v1], verts[v2]);
		norms[v0].x += normal.x;
		norms[v0].y += normal.y;
		norms[v0].z += normal.z;
		norms[v1].x += normal.x;
		norms[v1].y += normal.y;
		norms[v1].z += normal.z;
		norms[v2].x += normal.x;
		norms[v2].y += normal.y;
		norms[v2].z += normal.z;
	}

	for (int i = 0; i < nV; i++) {
		float len = sqrt(norms[i].x*norms[i].x +
			norms[i].y*norms[i].y +
			norms[i].z*norms[i].z);
		norms[i].x /= len;
		norms[i].y /= len;
		norms[i].z /= len;
	}
}

vertex CMesh::computeNormal(vertex a, vertex b, vertex c) {
	vertex normal;
	vertex u, v;
	u.x = b.x - a.x; u.y = b.y - a.y; u.z = b.z - a.z;
	v.x = c.x - a.x; v.y = c.y - a.y; v.z = c.z - a.z;
	normal.x = u.y * v.z - u.z * v.y;
	normal.y = u.x * v.z - u.z * v.x;
	normal.z = u.x * v.y - u.y * v.x;

	return normal;
}

void CMesh::read(char *fname) {
	FILE *f;
	fopen_s(&f, fname, "r");
	if (!f) { printf("file not found\n"); return; }

	fscanf(f, "%d", &nV);
	if (verts) delete[] verts;
	verts = new vertex[nV];
	if (norms) delete[] norms;
	norms = new vertex[nV];
	for (int i = 0; i < nV; i++) {
		fscanf(f, "%f", &verts[i].x);
		fscanf(f, "%f", &verts[i].y);
		fscanf(f, "%f", &verts[i].z);
		norms[i].x = norms[i].y = norms[i].z = 0.0;
	}
	fscanf(f, "%d", &nF);
	if (tris) delete[] tris;
	tris = new triangle[nF];
	for (int i = 0; i < nF; i++) {
		fscanf(f, "%d", &tris[i].v0);
		fscanf(f, "%d", &tris[i].v1);
		fscanf(f, "%d", &tris[i].v2);
	}

	computeNormals();
}

void CMesh::show() {

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < nF; i++) {

		// current face = tris[i]
		// three vertices : tris[i].v0, v1, v2
		int v0 = tris[i].v0;
		int v1 = tris[i].v1;
		int v2 = tris[i].v2;

		glNormal3f(norms[v0].x, norms[v0].y, norms[v0].z);
		glVertex3f(verts[v0].x, verts[v0].y, verts[v0].z);
		glNormal3f(norms[v1].x, norms[v1].y, norms[v1].z);
		glVertex3f(verts[v1].x, verts[v1].y, verts[v1].z);
		glNormal3f(norms[v2].x, norms[v2].y, norms[v2].z);
		glVertex3f(verts[v2].x, verts[v2].y, verts[v2].z);


	}
	glEnd();

}