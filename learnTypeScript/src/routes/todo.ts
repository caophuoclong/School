import { Router } from "express";
import { createTodo, getTodo, updateTodo } from "../controllers/todo";
const route = Router();
route.get("/", getTodo)
route.post("/", createTodo);
route.patch("/:id", updateTodo)

export default route;