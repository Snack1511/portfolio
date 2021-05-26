#include "mesh.h"

CMesh::CMesh() { }

CMesh::~CMesh() {
	delete[] verts;
}

void CMesh::computeNormals() {

}

vertex CMesh::computeNormal(vertex a, vertex b, vertex c) {
	vertex normal;
	vertex u, v;
	u.x = b.x - a.x; u.y = b.y - a.y; u.z = b.z - a.z;
	v.x = c.x - a.x; v.y = c.y - a.y; v.z = c.z - a.z;
	normal.x = u.y * v.z - u.z * v.y;
	normal.y = u.x * v.z - u.z * v.x;
	normal.z = u.x * v.y - u.y * v.x;
	float len = sqrt(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
	normal.x /= len;
	normal.y /= len;
	normal.z /= len;
	return normal;
}

vertex CMesh::computeNorms() {
	vertex p0, p1, p2;
	vertex vec1, vec2;
	vertex normal;

	for (int i = 0; i<nV; i++) {
		norms[i].x = norms[i].y = norms[i].z = 0.0;
	}

	for (int i = 0; i<nF; i++) {
		// compute normal for each face
		int v0, v1, v2;
		v0 = tris[i].v0; v1 = tris[i].v1; v2 = tris[i].v2;
		p0 = verts[v0];   p1 = verts[v1];   p2 = verts[v2];

		vec1.x = p1.x - p0.x; vec1.y = p1.y - p0.y; vec1.z = p1.z - p0.z;
		vec2.x = p2.x - p0.x; vec2.y = p2.y - p0.y; vec2.z = p2.z - p0.z;

		normal.x = vec1.y*vec2.z - vec1.z*vec2.y;
		normal.y = vec1.z*vec2.x - vec1.x*vec2.z;
		normal.z = vec1.x*vec2.y - vec1.y*vec2.x;

		// add the computed normal to normals of vertices in the face
		norms[v0].x += normal.x; norms[v0].y += normal.y; norms[v0].z += normal.z;
		norms[v1].x += normal.x; norms[v1].y += normal.y; norms[v1].z += normal.z;
		norms[v2].x += normal.x; norms[v2].y += normal.y; norms[v2].z += normal.z;
	}

	for (int i = 0; i<nV; i++) {
		// normalize n[i]
		float len = sqrt(norms[i].x*norms[i].x + norms[i].y*norms[i].y + norms[i].z*norms[i].z);
		norms[i].x /= len; norms[i].y /= len; norms[i].z /= len;
	}

	return (vertex)*norms;
}

void CMesh::read(char *fname) {
	FILE *f;
	fopen_s(&f, fname, "r");
	if (!f) { printf("file not found\n"); return; }

	fscanf(f, "%d", &nV);
	verts = new vertex[nV];
	norms = new vertex[nV];
	for (int i = 0; i < nV; i++) {
		fscanf(f, "%f", &verts[i].x);
		fscanf(f, "%f", &verts[i].y);
		fscanf(f, "%f", &verts[i].z);
	}
	fscanf(f, "%d", &nF);
	tris = new triangle[nF];
	for (int i = 0; i < nF; i++) {
		fscanf(f, "%d", &tris[i].v0);
		fscanf(f, "%d", &tris[i].v1);
		fscanf(f, "%d", &tris[i].v2);
	}

	computeNormals();
	computeNorms();
}

void CMesh::show() {

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < nF; i++) {

		// current face = tris[i]
		// three vertices : tris[i].v0, v1, v2
		int v0 = tris[i].v0;
		int v1 = tris[i].v1;
		int v2 = tris[i].v2;
		/*vertex normal = computeNormal(verts[v0], verts[v1], verts[v2]);
		glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(verts[v0].x, verts[v0].y, verts[v0].z);
		glVertex3f(verts[v1].x, verts[v1].y, verts[v1].z);
		glVertex3f(verts[v2].x, verts[v2].y, verts[v2].z);*/
		/*vertex normal = computeNormal(norms[v0], norms[v1], norms[v2]);
		glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(verts[v0].x, verts[v0].y, verts[v0].z);
		glVertex3f(norms[v1].x, norms[v1].y, norms[v1].z);
		glVertex3f(norms[v2].x, norms[v2].y, norms[v2].z);*/
		//
		glNormal3f(norms[v0].x, norms[v0].y, norms[v0].z);
		glVertex3f(verts[v0].x, verts[v0].y, verts[v0].z);
		glNormal3f(norms[v1].x, norms[v1].y, norms[v1].z);
		glVertex3f(verts[v1].x, verts[v1].y, verts[v1].z);
		glNormal3f(norms[v2].x, norms[v2].y, norms[v2].z);
		glVertex3f(verts[v2].x, verts[v2].y, verts[v2].z);
		


	}

	glEnd();

}