// A shader can't be used by itself - it must be attached to a shader program...


#ifndef _VERTEXSHADER_H
#define _VERTEXSHADER_H





// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------
class vertexshader
{
	public:
		GLuint			shaderID;								// OpenGL gives this to us (like a texture ID)
		GLchar			*shaderText;							// pointer to text shader source from text file


						vertexshader(string theFilename);		// default constructor
		virtual			~vertexshader();						// destructor


};


#endif // _VERTEXSHADER_H

