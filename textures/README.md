# 纹理文件夹

这个文件夹用于存放纹理图像文件。

## 使用方法

1. 将你的纹理图像（如JPG、PNG等格式）放在此文件夹中
2. 在代码中使用相对路径加载纹理，例如：`texture.load("textures/container.jpg")`

## 支持的格式

通过stb_image库，支持以下常见格式：
- JPG/JPEG
- PNG
- BMP
- TGA
- GIF
- PSD
- HDR
- PIC

## 注意事项

- 为获得最佳性能，建议使用2的幂次方尺寸的纹理（如256x256, 512x512等）
- 对于OpenGL，纹理坐标原点(0,0)在左下角，与许多图像编辑软件不同