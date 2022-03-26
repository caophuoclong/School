import IPromoteStrategy from "./IPromteStrategy";
class NoDiscount implements IPromoteStrategy {
    public doDiscount(price: number): number {
        return price;
    }
}

class HalfDiscount implements IPromoteStrategy {
    public doDiscount(price: number): number {
        return price * 0.5;
    }
}

class QuaterDiscount implements IPromoteStrategy {
    public doDiscount(price: number): number {
        return price * 0.25;
    }
}

class EightyPercentDiscount implements IPromoteStrategy {
    public doDiscount(price: number): number {
        return price * 0.8;
    }
}

export { NoDiscount, EightyPercentDiscount, HalfDiscount, QuaterDiscount };

