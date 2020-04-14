# Demo

A game framework for CLI

**The English part of README.md is translated by https://translate.google.cn.**

## Get the source code of this project

```shell
git clone git@github.com:MalachiteN/Demo.git # Use SSH
# OR
git clone https://github.com/MalachiteN/Demo.git # Use HTTPS
```

## Build

In order to compile this project, we need the latest Visual Studio. Its community version can be downloaded from Microsoft's official website.

Click "Build"-> "Build Solution" in the menu to compile the project. The compiled Demo will appear in `<Project Directory> / Debug / Demo.exe`  or  `<Project Directory> / Release / Demo.exe`.

This project does not depend on libraries provided by Visual Studio, but other compilation methods have not been verified.

## Usage

Add these few statements to your project to start using all of the framework:

```cpp
#include "std.h"
#include "cli.h"
```

# License

Demo is licensed under the GNU General Public License v3.0.
See the LICENSE file for details.

# Demo

一个基于命令行终端的游戏框架

## 如何获取该项目的源代码

```shell
git clone git@github.com:MalachiteN/Demo.git # Use SSH
# OR
git clone https://github.com/MalachiteN/Demo.git # Use HTTPS
```

## 如何编译

为了编译这个项目，我们需要最新的 Visual Studio。在微软官网可以下载到它的社区版本。

在菜单点击 “生成” -> “生成解决方案” 以编译该项目。编译出的 Demo 会出现在`<项目目录> / Debug / Demo.exe`  或  `<项目目录> / Release / Demo.exe`中。

本项目没有依赖 Visual Studio 提供的库，但其他编译方式尚未经过验证。

## 使用方法

在你的项目中加入

```cpp
#include "std.h"
#include "cli.h"
```

即可开始使用。

值得注意的是，你的项目也需要由 Visual Studio 编译。

## 开源许可协议

Demo 是根据 GNU General Public License v3.0 协议许可的。
详见 LICENSE 文件。