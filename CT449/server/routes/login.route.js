const express = require("express");
const api = express.Router();
const auth_controller = require("../controllers/login.controller");
api.post("/login", auth_controller.login);
api.post("/signup", auth_controller.signup);
module.exports = api;
