package model;

import java.time.LocalDate;

public class Registration {

	private int registrationNo;
	private int rollNo;
	private int courseId;
	 private LocalDate registrationDate;
	public Registration(int rollNo, int courseId, LocalDate registrationDate) {
		super();
		this.rollNo = rollNo;
		this.courseId = courseId;
		this.registrationDate = registrationDate;
	}
	public Registration() {
		// TODO Auto-generated constructor stub
	}
	public int getRollNo() {
		return rollNo;
	}
	public void setRollNo(int rollNo) {
		this.rollNo = rollNo;
	}
	public int getCourseId() {
		return courseId;
	}
	public void setCourseId(int courseId) {
		this.courseId = courseId;
	}
	public LocalDate getRegistrationDate() {
		return registrationDate;
	}
	public void setRegistrationDate(LocalDate registrationDate) {
		this.registrationDate = registrationDate;
	}
	public int getRegistrationNo() {
		return registrationNo;
	}
	    
}
