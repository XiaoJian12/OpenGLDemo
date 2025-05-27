# OpenGL 学习框架

这是一个为OpenGL初学者设计的简单框架，帮助你快速开始OpenGL编程学习。

## 项目结构

```
GLDemo/
├── CMakeLists.txt      # CMake配置文件
├── src/                # 源代码目录
│   └── main.cpp        # 主程序
├── include/            # 头文件目录
├── external/           # 第三方库
│   └── glad/           # GLAD库
└── shaders/            # 着色器文件目录
```

## 依赖项

- CMake 3.10+
- C++17 兼容的编译器
- OpenGL
- GLFW (会自动下载)
- GLAD (需要手动下载)

## 配置GLAD

在开始构建项目前，你需要下载GLAD：

1. 访问 [GLAD在线服务](https://glad.dav1d.de/)
2. 选择语言: C/C++
3. 选择API: OpenGL
4. 选择版本: 3.3+
5. 选择配置文件: Core
6. 勾选生成加载器
7. 点击生成
8. 下载生成的zip文件
9. 解压到 `external/glad` 目录，确保目录结构如下：
   ```
   external/glad/
   ├── include/
   │   ├── glad/
   │   │   └── glad.h
   │   └── KHR/
   │       └── khrplatform.h
   └── src/
       └── glad.c
   ```

## 构建项目

```bash
# 创建构建目录
mkdir build
cd build

# 配置CMake
cmake ..

# 构建项目
cmake --build .
```

## 运行

构建完成后，可执行文件将位于 `build/bin` 目录下。

## 学习资源

- [LearnOpenGL](https://learnopengl.com/) - 优秀的OpenGL教程
- [OpenGL官方文档](https://www.opengl.org/documentation/)
- [GLFW文档](https://www.glfw.org/documentation.html)

## 下一步

1. 学习着色器编程
2. 添加基本图形渲染
3. 实现纹理映射
4. 探索3D变换和摄像机系统

祝你学习OpenGL愉快！