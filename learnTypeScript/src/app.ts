import casual from 'casual';
type genderType = 'm' | 'f';
class Employee {
  private _id: string;
  private _name: string;
  private _age: number;
  private _gender: genderType;
  private _email: string;
  constructor(name: string, age: number, gender: genderType, email: string) {
    this._id = casual.uuid;
    this._name = name;
    this._age = age;
    this._email = email;
    this._gender = gender;
  }
  public get id(): string {
    return this._id;
  }
  public set id(value: string) {
    this._id = value;
  }
  public get name(): string {
    return this._name;
  }
  public set name(value: string) {
    this._name = value;
  }
  public get age(): number {
    return this._age;
  }
  public set age(value: number) {
    this._age = value;
  }
  public get gender(): genderType {
    return this._gender;
  }
  public set gender(value: genderType) {
    this._gender = value;
  }
  public get email(): string {
    return this._email;
  }
  public set email(value: string) {
    this._email = value;
  }
}
class Deparment {
  private _id: string;
  private _name: string;
  protected _employes: Array<Employee>;
  constructor(name: string) {
    this._id = casual.uuid;
    this._name = name;
    this._employes = [];
  }
  public get id(): string {
    return this._id;
  }
  public addEmployee(employee: Employee): void {
    this._employes.push(employee);
  }
  public get employee(): Array<Employee> {
    return this._employes;
  }
  public get name(): string {
    return this._name;
  }
  public set name(value: string) {
    this._name = value;
  }
}

class ITDepartment extends Deparment {
  constructor(name: string) {
    super(name);
  }
  public addEmployee(employee: Employee): void {
    this._employes.push(employee);
  }
}

const ELong = new Employee(casual.name, 30, 'm', 'caophuoclong1@gmail.com');
console.log(ELong);
