#include "pch.h"
#include "OpenGLImage.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "GameUtil.h"

namespace Game
{
	OpenGLImage::OpenGLImage(const std::string& imageFile)
	{
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &Width, &Height, &nrChannels, 0);

		if (data == nullptr) {
			GAME_ERROR("ERROR: Image reading has failed");
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

	}
	OpenGLImage::OpenGLImage(std::string&& imageFile)
	{
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &Width, &Height, &nrChannels, 0);

		if (data == nullptr) {
			GAME_ERROR("ERROR: Image reading has failed");
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);


		stbi_image_free(data);
	}
	void OpenGLImage::Activate()
	{
		glBindTexture(GL_TEXTURE_2D, texture1);
	}

	int OpenGLImage::GetWidth() const
	{
		return Width;
	}

	int OpenGLImage::GetHeight() const
	{
		return Height;
	}

	OpenGLImage::~OpenGLImage()
	{
		glDeleteTextures(1, &texture1);
	}
}