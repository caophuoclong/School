const jwt = require("jsonwebtoken");
const casual = require("casual");
module.exports = {
  login: (req, res) => {
    const { username, password } = req.body;
    const url = "/";
    const account = {
      username,
      password,
      url,
    };
    return res.send(account);
  },
  signup: (req, res) => {},
};
