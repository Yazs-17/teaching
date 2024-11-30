
# Introduce to Document Object Model

- 文本对象模型

JavaScript DOM Crash Course - 速食课程大纲

简单讲解一下作业内容，


 - 成员在抽奖系统 JS 源码普遍使用了`document.createElement()` 、`document.getElementById()`等语句对 HTML 相应元素的处理
 - 




HTML - Structure 
CSS - Style
JS - Function - 操作




之前的JS 语法课中

 - 可能初步认识了一下 JS 的相关语法，在完成作业的过程中，大家也可能已经了解了相关 HTML 页面的构建，那么一门脚本语言是如何来影响或者说是操作页面结构的呢？

画一下 HTML 的结构图 

[[Drawing 2024-11-27 18.09.05.excalidraw]]

DOM
```html
<!DOCTYPE html>
<html>
<head>
    <title>Document</title>
</head>
<body>
    <!-- li*30>lorem -->
</body>
</html>


```

那么在DOM 中，是如何来展示 html 的，


是一种类似树形的结构

 - HTML Generator Tree

好，现在我们准备一个样例文件：[[index.html]]

```js
// 获取 
document //发现返回所有内容
document.getElementsByTagName("head")
document.getElementsByTagName("body")// 返回很多东西，s，负数
document.get ... 选择
document.getElementsByClassName("demo")




// css 选择器



document.querySelector - 返回文档中匹配指定CSS 选择器的一个元素 - 按照css选择器的选择方式匹配页面元素

document.querySelectorAll,通过下标的方式选择具体元素


#title

F12 调试器

添加器


document.querySelector("h1").classList.toggle(""); // 添加或者删除相关的东西

document.querySelector("h1").classList.toggle("demo");


document.querySelector("button").addEventListener("click", function() {
    document.querySelector("h1").classList.toggle("demo");
})

document.querySelector("h1").innerHTML = "hello";

document.querySelector("h1").textContent;

document.querySelector("h1").attributes;


document.querySelector("h1").attributes.class.value = "title demo";

```


attribute














## 整合之前所讲

- HTML - 结构
- CSS - 样式
- JavaScript语法基础

但之前所讲的 JS 只是

##  讲一下 JS 如何修改
