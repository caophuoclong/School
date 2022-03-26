import { NextFunction, Request, RequestHandler, Response } from "express";
import { Todo } from "../models/todo";
const TODOS: Array<Todo> = [];
export const createTodo: RequestHandler = (req, res, next) => {
    const { text } = <{ text: string }>req.body;
    console.log(text);
    const newTodo = new Todo(Math.random.toString(), text);
    res.status(200).json({
        message: "Create todo success"
    })
    TODOS.push(newTodo);
}
export const getTodo: RequestHandler = (req, res, next) => {
    res.json({
        todos: TODOS
    })
}
export const updateTodo: RequestHandler<{ id: string }> = (req, res, next) => {
    const { id } = req.params;

}