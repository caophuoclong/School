export default interface IPromoteStrategy {
    doDiscount: (price: number) => number;
}