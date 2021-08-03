document.querySelectorAll("p.lang").forEach((element, a) => {
  element.addEventListener("click", (w) => {
    if (w.path[0].id === "vn") {
      document.getElementById("en").classList.remove("selected");
    } else {
      document.getElementById("vn").classList.remove("selected");
    }
    element.classList.add("selected");
  });
});
const formLogin = $("#form-login");
formLogin.on("submit", async (e) => {
  e.preventDefault();
  const x = formLogin.serialize();
  console.log(x);
  // const account = {
  //   username,
  //   password,
  // };
  // const url_login = "http://localhost:3000/api/login";
  // const data = await axios.post(url_login, (params = account), {
  //   "Access-Control-Allow-Origin": "*",
  // });
  // console.log(data);
  // window.location.href = data.data.url;
  // console.log(data);
});
