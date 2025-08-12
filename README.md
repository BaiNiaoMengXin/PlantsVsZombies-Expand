# PlantsVsZombies-Expand

[![许可协议]
](https://www.gnu.org/licenses/gpl-3.0.html)

*一个基于Github上PlantsVsZombies-AndroidTV项目的改版*

## 构建

> [!NOTE]
> 需要资源文件请联系仓库作者

使用 Android Studio 或其他支持 gradle 的 IDE, 要求已安装:

- Android SDK Platform 34
- NDK v27.2.12479018
- CMake v3.20+

签名配置位于项目根目录的 `keystore.properties` 文件中 (需要自行创建), 文件内容样式如下:

```properties
storePassword=myStorePassword
keyPassword=mykeyPassword
keyAlias=myKeyAlias
storeFile=myStoreFileLocation
```

## 编码风格

### 命名

- 类: `ClassName`
- 变量: `varName`
- 命名空间: `name_space_name`
- 宏/常量/枚举量: `MACRO_NAME`

### 其他

见项目根目录下的 `.clang-format` 文件.

> 建议在每次提交更改前先用 IDE 对代码进行格式化.

## 许可协议

```
Copyright (C) 2023-2025  PvZ TV Touch Team

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
```
