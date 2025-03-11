# README for MyNew AWE Test Module

## 模块概述
本模块用于测试Audio Weaver (AWE)框架下创建基础模块的功能，核心功能是将输入音频流直接拷贝到输出端。

## 模块特性
- 实现音频流直通功能（input → output）
- 支持多种数据类型（float/int/fract32）
- 包含日志跟踪功能

### 环境要求
- Visual Studio 2019
- MATLAB（用于模块代码生成）
- Audio Weaver SDK

### 构建步骤
1. 更新模块库（MATLAB）：
   ```matlab
   make_my_new_module_pack
   ```

2. 构建模块代码（VS）：
    ```bash
    # 使用 Visual Studio 解决方案构建
    MSBuild MyNew_2019.sln /p:Configuration=Release

    # 或使用 Visual Studio IDE：
    # 1. 双击打开 MyNew_2019.sln
    # 2. 选择 Release 配置
    # 3. 生成 -> 生成解决方案
    ```
