import { EightyPercentDiscount, HalfDiscount, NoDiscount, QuaterDiscount } from "./Discount";
import Ticket from "./Ticket";

for (let i = 1; i <= 5; i++) {
    console.group("Ticket " + i);
    let ticket = new Ticket();
    ticket.name = "Ticket " + i;
    ticket.price = i * 50;
    // random from 0 to 3
    let random = Math.floor(Math.random() * 4);
    switch (random) {
        case 0:
            ticket.promteStrategy = new NoDiscount();
            break;
        case 1:
            ticket.promteStrategy = new HalfDiscount();
            break;
        case 2:
            ticket.promteStrategy = new QuaterDiscount();
            break;
        case 3:
            ticket.promteStrategy = new EightyPercentDiscount();
            break;
        default:
            break;
    }
    console.log("Price: " + ticket.price);
    console.log("Price after discount: " + ": " + ticket.getPromteStrategy());
    console.groupEnd();
}