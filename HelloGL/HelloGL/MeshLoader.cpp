#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
		inFile >> mesh.NormalCount;

		mesh.Normals = new Vector3[mesh.NormalCount];

		for (int i = 0; i < mesh.NormalCount; i++)
		{
			inFile >> mesh.Normals[i].x;
			inFile >> mesh.Normals[i].y;
			inFile >> mesh.Normals[i].z;
		}
		
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;

		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			inFile >> mesh.TexCoords[i].u;
			inFile >> mesh.TexCoords[i].v;
		}
	}


	// PROBLEM IS HERE, INDEXCOUNTER 0 IM GOING TO TRY AND FIND OUT WHAT THIS IS BEFORE I SEE LUKE TOMORROW MORNING
	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
		inFile >> mesh.IndexCount;

		mesh.Indices = new GLushort[mesh.IndexCount];

		// Array only cycles once
		for (int i = 0; i < mesh.IndexCount; i++)
		{
			inFile >> mesh.Indices[i];
		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		//LOAD DATA USING METHODS ABOVE
		LoadVertices(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadIndices(inFile, *mesh);
		
		


		return mesh;
	}

}