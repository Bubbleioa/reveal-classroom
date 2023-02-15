# reveal-classroom

适合于授课的 reveal.js 主题。

```
.
├── classRoom.css // 自定义 css
├── dist          // 图片等静态文件
├── export        // 导出的静态页面（生成）
└── slide.md      // slide 主体
```

## 开始使用

首先安装 vscode 插件 `vscode-reveal`。

编辑 slide.md

`Ctrl+shift+p` 后搜索 Reveal，选择 `Open presentation in brower`（开发） 或者 `Export to HTML`（发布）

编写相关问题请参照本仓库中的`slide.md`。

## Q&A

**Q1: 我想更改图文排版怎么办？**

支持`tailwind css`，请参考`slide.md`中的配置。