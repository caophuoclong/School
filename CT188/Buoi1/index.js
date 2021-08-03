const danhmuc = document.getElementById("text-danhmuc");
danhmuc.addEventListener("click", () => {
  const element = document.getElementById("side-bar-danhmuc");
  if (element.classList.contains("hide")) {
    element.classList.remove("hide");
  } else {
    element.classList.add("hide");
  }
});
const menu = document.getElementById("text-menu");
menu.addEventListener("click", () => {
  const element = document.getElementById("side-bar-menu");
  if (element.classList.contains("hide")) {
    element.classList.remove("hide");
  } else {
    element.classList.add("hide");
  }
});
