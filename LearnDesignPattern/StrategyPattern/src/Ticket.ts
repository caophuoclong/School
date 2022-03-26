import IPromoteStrategy from "./IPromteStrategy";

class Ticket {
    private _name: string;
    private _price: number;
    private _promteStrategy: IPromoteStrategy;

    public get name(): string {
        return this._name;
    }

    public get price(): number {
        return this._price;
    }

    public getPromteStrategy(): number {
        return this._promteStrategy.doDiscount(this._price);
    }

    public set name(value: string) {
        this._name = value;
    }

    public set price(value: number) {
        this._price = value;
    }

    public set promteStrategy(promoteStrategy: IPromoteStrategy) {
        this._promteStrategy = promoteStrategy;
    }
}
export default Ticket;