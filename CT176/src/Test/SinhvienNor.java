package Test;

public class SinhvienNor extends Sinhvien {
	public SinhvienNor(){
		super();
	}
	public SinhvienNor(SinhvienNor sv){
		super(sv);
	}
	public void Nhap(){
		super.Nhap();
	}
	public String toString()
	{
		return super.toString();
	}
	@Override
	String getEmail() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	void changePass(String args) {
		// TODO Auto-generated method stub
		
	}

	@Override
	String getUsername() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	String getPass() {
		// TODO Auto-generated method stub
		return null;
	}
	

}
