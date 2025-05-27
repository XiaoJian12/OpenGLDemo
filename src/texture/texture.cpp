#include "texture.h"
#include <iostream>

// 定义STB_IMAGE_IMPLEMENTATION，使stb_image.h包含函数定义
#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image/stb_image.h"

Texture::Texture() : textureID(0), width(0), height(0), channels(0) {
    // 生成一个纹理ID
    glGenTextures(1, &textureID);
}

Texture::~Texture() {
    // 删除纹理
    if (textureID != 0) {
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }
}

bool Texture::load(const std::string& path) {
    // 绑定纹理对象
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // 设置纹理环绕和过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // 加载图像
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data) {
        // 根据图像通道数确定格式
        GLenum format;
        if (channels == 1)
            format = GL_RED;
        else if (channels == 3)
            format = GL_RGB;
        else if (channels == 4)
            format = GL_RGBA;
        else {
            std::cerr << "不支持的图像格式，通道数: " << channels << std::endl;
            stbi_image_free(data);
            return false;
        }
        
        // 生成纹理
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        // 释放图像数据
        stbi_image_free(data);
        return true;
    } else {
        std::cerr << "无法加载纹理: " << path << std::endl;
        std::cerr << "STB错误: " << stbi_failure_reason() << std::endl;
        return false;
    }
}

void Texture::bind(unsigned int textureUnit) const {
    // 激活指定的纹理单元
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    // 绑定纹理
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() const {
    // 解绑纹理
    glBindTexture(GL_TEXTURE_2D, 0);
}