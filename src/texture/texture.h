#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glad/glad.h>

class Texture {
public:
    // 构造函数和析构函数
    Texture();
    ~Texture();

    // 加载纹理
    bool load(const std::string& path);
    
    // 绑定纹理到当前活动的纹理单元
    void bind(unsigned int textureUnit = 0) const;
    
    // 解绑纹理
    void unbind() const;
    
    // 获取纹理ID
    unsigned int getID() const { return textureID; }
    
    // 获取纹理宽度和高度
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    unsigned int textureID; // OpenGL纹理ID
    int width;              // 纹理宽度
    int height;             // 纹理高度
    int channels;           // 纹理通道数
};

#endif // TEXTURE_H