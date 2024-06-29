# Lifegame 生命游戏

## 项目介绍

Lifegame 是一个基于 C++ 的生命游戏实现，结合了 vs 与 easyx 图形库，以 easyx 窗口作为主要界面，同时使用终端黑窗口进行辅助操作。

## 功能实现

### 一、用户登录注册

- 用户可以进行登录、注册、删除等操作。
- 用户可以查看已经注册过的用户名与密码，用户名与密码保存在 txt 文件中。

### 二、图片插入与音乐播放功能

- 实现了图片的插入功能。
- 实现了音乐的播放功能。

### 三、生命游戏的基本和扩展操作

#### 1. 游戏模式

- **随级模式**：依据随机种子自动生成细胞。
- **手绘模式**：用户可以自由画图，点击最右下角的方块即可结束画图。

#### 2. 游戏控制

- **暂停/继续**：在演化过程中可以进行暂停或继续操作。
- **倍速功能**：可以任意调控游戏的演化速度。
- **细胞控制**：鼠标右键点击细胞可以让细胞死亡。

#### 3. 自定义设置

- **颜色调控**：可以依据 RGB 三值任意调控细胞颜色。
- **速度调控**：除了倍速功能，还可以进行更细粒度的速度调控。

#### 4. 模型放置

- **经典模型**：提供了生命游戏中经典的 5 个模型，点击即可放置。

#### 5. 日志功能

- **保存状态**：先点击保存即可记录所有细胞此刻的状态（保存到 txt 文件中）。
- **查看状态**：再点击查看即可查看最新保存的细胞状态。

#### 6. 退出游戏

- 设置了登出按钮，点击即可退出游戏。


