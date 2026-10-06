#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class menu
{
public:
	void main_menu()
	{
		cout << "------------------------------欢迎来到机房预约系统------------------------------" << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              1,学生                                          -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              2,老师                                          -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              3,管理员                                        -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              0,退出                                          -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "请输入数字进行选择:" << endl;
	}
	void student_menu()
	{
		cout << "------------------------------欢迎来到学生界面----------------------------------" << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              1,申请预约                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              2,查看我的预约                                  -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              3,查看机房预约情况                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              4,取消预约                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              0,注销学生登录                                  -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "请输入数字进行选择:" << endl;
	}
	void teacher_menu()
	{
		cout << "------------------------------欢迎来到老师界面----------------------------------" << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              1,查看所有预约                                  -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              2,审核预约                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              0,注销老师登录                                  -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "请输入数字进行选择:" << endl;
	}
	void administrator_menu()
	{
		cout << "------------------------------欢迎来到管理员界面--------------------------------" << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              1,添加账号                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              2,查看账号                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              3,添加机房                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              4,查看机房                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              5,清空预约                                      -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                              0,注销管理员登录                                -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "-                                                                              -" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "请输入数字进行选择:" << endl;
	}
};
class com_room
{
public:
	vector<vector<int>>room;
};
class appointment
{
private:
	string date="";
	string time="";
	int room;
	string appointment_status="";
public:
	appointment& operator=(appointment& a)
	{
		this->date = a.getdate();
		this->time = a.gettime();
		this->room = a.getroom();
		this->appointment_status = a.getappointment_status();
		return *this;
	}
	void setdate()
	{
		int date_num;
		cout << "请输入数字选择日期:" << endl;
		cout << "1,周一" << endl;
		cout << "2,周二" << endl;
		cout << "3,周三" << endl;
		cout << "4,周四" << endl;
		cout << "5,周五" << endl;
		while (true)
		{
			cin >> date_num;
			if (cin.fail() || date_num < 1 || date_num>5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		switch (date_num)
		{
			case 1:
				date = "周一";
				break;
			case 2:
				date = "周二";
				break;
			case 3:
				date = "周三";
				break;
			case 4:
				date = "周四";
				break;
			case 5:
				date = "周五";
				break;
			default:
				cout << "数字输入错误" << endl;
				break;
		}
	}
	void settime()
	{
		int time_num;
		cout << "请输入数字选择时段:" << endl;
		cout << "1,上午" << endl;
		cout << "2,下午" << endl;
		while (true)
		{
			cin >> time_num;
			if (cin.fail() || time_num < 1 || time_num>2)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		switch (time_num)
		{
			case 1:
				time = "上午";
				break;
			case 2:
				time = "下午";
				break;
			default:
				cout << "数字输入错误" << endl;
				break;
		}
	}
	void setroom(com_room& room0)
	{
		cout << "目前系统中有" << room0.room.size() << "个机房" << endl;
		int room_num;
		for (int x = 0;;x++)
		{
			cout << "请输入对应数字选择机房" << endl;
			cin >> room_num;
			if (room_num <= room0.room.size())
			{
				room = room_num;
				break;
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '/n');
				cout << "输入错误,请重新输入:" << endl;
			}
			else
			{
				cout << "系统中没有该机房,请重新输入:" << endl;
			}
		}
	}
	void setappointment_status(int status_num)
	{ 
		switch (status_num)
		{
			case 1:
			{
				appointment_status = "申请中";
				break;
			}
			case 2:
			{
				appointment_status = "已取消" ;
				break;
			}
			case 3:
			{
				appointment_status = "已通过" ;
				break;
			}
			case 4:
			{
				appointment_status = "未通过" ;
				break;
			}
			case 0:
			{
				appointment_status = "";
				break;
			}
		}
	}
	string getdate()
	{
		return date;
	}
	string gettime()
	{
		return time;
	}
	int getroom()
	{
		return room;
	}
	string getappointment_status()
	{
		return appointment_status;
	}
};
class student
{
private:

	int student_num;
	string student_name = "";
	int student_password = 0;
	appointment student_appointment;

public:
	void setnum(int num)
	{
		student_num = num;
	}
	int getnum()
	{
		return student_num;
	}
	void setname(string name)
	{
		student_name = name;
	}
	string getname()
	{
		return student_name;
	}
	void setpassword(int password)
	{
		student_password = password;
	}
	int getpassword()
	{
		return student_password;
	}
	void setappointment(appointment& a)
	{
		student_appointment = a;
	}
	appointment& getappointment()
	{
		return student_appointment;
	}

};
class teacher
{
private:
	string teacher_name = "";
	int teacher_password = 0;
public:
	void setname(string name)
	{
		teacher_name = name;
	}
	string getname()
	{
		return teacher_name;
	}
	void setpassword(int password)
	{
		teacher_password = password;
	}
	int getpassword()
	{
		return teacher_password;
	}
};
class systemData
{
public:
	vector<student>v_student;
	vector<teacher>v_teacher;
	vector<appointment>v_appointment;
	menu menu01;
};
class studentWork
{
public:
	int v_stu_num;
	int temp_num = 0;
	void loginstudent_work(systemData& data,com_room& room0)
	{
		int login_student_num;
		string login_student_name = "";
		int login_student_password = 0;
		cout << "请输入您的学号:" << endl;
		while (true)
		{
			cin >> login_student_num;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		cout << "请输入您的姓名:" << endl;
		while (true)
		{
			cin >> login_student_name;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		cout << "请输入您的密码:" << endl;
		while (true)
		{
			cin >> login_student_password;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		system("pause");
		system("cls");
		for (v_stu_num = 0;v_stu_num < data.v_student.size();v_stu_num++)
		{
			if (data.v_student[v_stu_num].getnum() == login_student_num && data.v_student[v_stu_num].getname() == login_student_name && data.v_student[v_stu_num].getpassword() == login_student_password)
			{
				for (int j = 0;;j++)
				{
					data.menu01.student_menu();
					int stu_choose;
					while (true)
					{
						cin >> stu_choose;
						if (cin.fail() || stu_choose < 0 || stu_choose>4)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "输入错误,请重新输入:" << endl;
							continue;
						}
						break;
					}
					switch (stu_choose)
					{
					case 1:
						{
							appointment a;
							if (data.v_student[v_stu_num].getappointment().getappointment_status() != "申请中" && data.v_student[v_stu_num].getappointment().getappointment_status() != "已通过")
							{
								a.setroom(room0);
								for (int b = 0;b != room0.room.size();b++)
								{
									if (b + 1 == a.getroom())
									{
										if (room0.room[b].size() <= room0.room[b].capacity())
										{
											a.setdate();
											a.settime();
											a.setappointment_status(1);
											data.v_appointment.push_back(a);
											data.v_student[v_stu_num].setappointment(a);
											cout << "已提交申请" << endl;
										}
										else
										{
											cout << "您所预约的机房已满,请换一个机房试试" << endl;
										}
									}
								}
							}
							else
							{
								cout << "您已申请预约" << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 2:
						{
							cout << "您的预约日期为: " << data.v_student[v_stu_num].getappointment().getdate() << " 您的预约时段为: " << data.v_student[v_stu_num].getappointment().gettime() << " 您的预约机房为:" << data.v_student[v_stu_num].getappointment().getroom()<<"号机房 " << " 您的预约状态为: " << data.v_student[v_stu_num].getappointment().getappointment_status() << endl;
							system("pause");
							system("cls");
							break;
						}
						case 3:
						{
							int m = 0;
							cout << "目前机房占有情况如下:" << endl;
							for (int c = 0;c < room0.room.size();c++)
							{
								for (int q = 0;q < room0.room[c].size();q++)
								{
									vector<int>temp_v = room0.room[c];
									if (temp_v[q] != 0)
									{
										m++;
									}
								}
								cout << c + 1 << "号机房: " << m << "/" << room0.room[c].capacity() << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 4:
						{
							int temp_cancel_num;
							cout << "是否取消预约" << endl;
							cout << "若是，请输入1；若否，请输入2" << endl;
							while (true)
							{
								cin >> temp_cancel_num;
								if (cin.fail() || temp_cancel_num < 1 || temp_cancel_num>2)
								{
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "输入错误,请重新输入:" << endl;
									continue;
								}
								break;
							}
							if (temp_cancel_num == 1)
							{
								data.v_student[v_stu_num].getappointment().setappointment_status(2);
								for (int i = 0;i < room0.room[data.v_student[v_stu_num].getappointment().getroom() - 1].capacity();i++)
								{
									if (room0.room[data.v_student[v_stu_num].getappointment().getroom() - 1][i] == 1)
									{
										room0.room[data.v_student[v_stu_num].getappointment().getroom() - 1][i] = 0;
										break;
									}
								}
								cout << "取消预约成功" << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							int temp_out_num;
							cout << "是否退出当前的学生登录" << endl;
							cout << "若是，请输入1；若否，请输入2" << endl;
							while (true)
							{
								cin >> temp_out_num;
								if (cin.fail() || temp_out_num < 1 || temp_out_num>2)
								{
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "输入错误,请重新输入:" << endl;
									continue;
								}
								break;
							}
							if (temp_out_num == 1)
							{
								cout << "退出登录成功" << endl;
								system("pause");
								system("cls");
								return;
							}
							system("pause");
							system("cls");
							break;
						}
					}
				}
				temp_num = 1;
			}
		}
		if (temp_num == 0)
		{
			cout << "输入错误，登录失败" << endl;
		}
		temp_num = 0;
		system("pause");
		system("cls");
	}
	
};
class teacherWork
{
public:
	int v_tea_num;
	int temp_num = 0;
	void loginteacher_work(systemData& data,com_room& room0)
	{
		string login_teacher_name = "";
		int login_teacher_password = 0;
		cout << "请输入您的姓名:" << endl;
		while (true)
		{
			cin >> login_teacher_name;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		cout << "请输入您的密码:" << endl;
		while (true)
		{
			cin >> login_teacher_password;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		system("pause");
		system("cls");
		for (v_tea_num = 0;v_tea_num < data.v_teacher.size();v_tea_num++)
		{
			if (data.v_teacher[v_tea_num].getname() == login_teacher_name && data.v_teacher[v_tea_num].getpassword() == login_teacher_password)
			{
				for (int j = 0;;j++)
				{
					data.menu01.teacher_menu();
					int tea_choose;
					while (true)
					{
						cin >> tea_choose;
						if (cin.fail() || tea_choose < 0 || tea_choose>2)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "输入错误,请重新输入:" << endl;
							continue;
						}
						break;
					}
					switch (tea_choose)
					{
						case 1:
						{
							cout << "所有学生的预约情况如下:" << endl;
							cout << endl;
							for (vector<student>::iterator it = data.v_student.begin();it != data.v_student.end() && it->getappointment().getappointment_status() != "";it++)
							{
								cout << "学号: " << it->getnum() << " 姓名: " << it->getname() << " 预约日期: " << it->getappointment().getdate() << " 预约时段: " << it->getappointment().gettime() << " 预约机房: " << it->getappointment().getroom()<<" 号机房 " << " 预约情况: " << it->getappointment().getappointment_status() << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 2:
						{
							int m = 0;
							cout << "目前机房占有情况如下:" << endl;
							for (int c = 0;c < room0.room.size();c++)
							{
								for (int q = 0;q < room0.room[c].size();q++)
								{
									vector<int>temp_v = room0.room[c];
									if (temp_v[q] != 0)
									{
										m++;
									}
								}
								cout << c + 1 << "号机房: " << m << "/" << room0.room[c].capacity() << endl;
							}
							cout << endl;
							vector<student>v_check_student;
							int n = 0;
							for (vector<student>::iterator it = data.v_student.begin();it != data.v_student.end();it++)
							{
								if (it->getappointment().getappointment_status() == "申请中")
								{
									n++;
									cout << n << "," << "学号: " << it->getnum() << " 姓名: " << it->getname() << " 预约日期: " << it->getappointment().getdate() << " 预约时段: " << it->getappointment().gettime() << " 预约机房: " << it->getappointment().getroom() << " 预约情况: " << it->getappointment().getappointment_status() << endl;
									v_check_student.push_back(*it);
								}
							}
							if (n != 0)
							{
								int temp_num = 0;
								int k = 0;
								cout << "请输入想要审核的预约学生的编号:" << endl;
								int check_num;
								while (true)
								{
									cin >> check_num;
									if (cin.fail() || check_num < 0 || check_num>n)
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								cout << "1,通过;2，不通过" << endl;
								cout << "请输入对应数字以表示审核结果:" << endl;
								int result_num;
								while (true)
								{
									cin >> result_num;
									if (cin.fail() || result_num < 1 || result_num>2)
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								if (result_num == 1)
								{
									for (vector<student>::iterator it = data.v_student.begin();it != data.v_student.end();it++)
									{
										if (v_check_student[check_num - 1].getnum() == it->getnum())
										{
											it->getappointment().setappointment_status(3);
											for (int i = 0;i < room0.room[it->getappointment().getroom() - 1].capacity();i++)
											{
												if (room0.room[it->getappointment().getroom() - 1][i] == 0)
												{
													room0.room[it->getappointment().getroom() - 1][i] = 1;
													for (int q = 0;q < room0.room[it->getappointment().getroom() - 1].size();q++)
													{
														vector<int>temp_v = room0.room[it->getappointment().getroom() - 1];
														if (temp_v[q] != 0)
														{
															k++;
														}
													}
													if (room0.room[it->getappointment().getroom() - 1].size() != k)
													{
														temp_num = 1;
													}
													if (temp_num == 0)
													{
														cout << "该机房已满,将拒绝剩余申请该机房的学生" << endl;
														vector<student>v_check_student01;
														for (vector<student>::iterator it1 = data.v_student.begin();it1 != data.v_student.end();it1++)
														{
															if (it1->getappointment().getappointment_status() == "申请中" && room0.room[it1->getappointment().getroom() - 1] == room0.room[it->getappointment().getroom() - 1])
															{
																it1->getappointment().setappointment_status(4);
															}
														}
													}
													break;
												}
											}
										}
									}
								}
								else if (result_num == 2)
								{
									for (vector<student>::iterator it = data.v_student.begin();it != data.v_student.end();it++)
									{
										if (v_check_student[check_num - 1].getnum() == it->getnum())
										{
											it->getappointment().setappointment_status(4);
										}
									}
								}
								
							}
							else
							{
								cout << "目前没有人申请预约" << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							int temp_out_num;
							cout << "是否退出当前的老师登录" << endl;
							cout << "若是，请输入1；若否，请输入2" << endl;
							while (true)
							{
								cin >> temp_out_num;
								if (cin.fail() || temp_out_num < 1 || temp_out_num>2)
								{
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "输入错误,请重新输入:" << endl;
									continue;
								}
								break;
							}
							if (temp_out_num == 1)
							{
								cout << "退出登录成功" << endl;
								system("pause");
								system("cls");
								return;
							}
							system("pause");
							system("cls");
							break;
						}
					}
				}
				temp_num = 1;
			}
		}
		if (temp_num == 0)
		{
			cout << "输入错误，登录失败" << endl;
		}
		temp_num = 0;
		system("pause");
		system("cls");
	}
};
class administratorWork
{
public:
	int v_ad_num;
	int temp_num = 0;
	void loginadministrator_work(systemData& data,com_room& room0)
	{
		string login_ad_name;
		int login_ad_password = 0;
		cout << "请输入您的姓名:" << endl;
		while (true)
		{
			cin >> login_ad_name;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		cout << "请输入您的密码:" << endl;
		while (true)
		{
			cin >> login_ad_password;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误,请重新输入:" << endl;
				continue;
			}
			break;
		}
		system("pause");
		system("cls");
		if (login_ad_name == "管理员01" && login_ad_password == 123)
		{
			temp_num = 1;
			for (int y = 0;;y++)
			{
				data.menu01.administrator_menu();
				int ad_choose;
				while (true)
				{
					cin >> ad_choose;
					if (cin.fail() || ad_choose < 0 || ad_choose>5)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "输入错误,请重新输入:" << endl;
						continue;
					}
					break;
				}
				switch (ad_choose)
				{
					case 1:
					{
						cout << "1,学生;2,老师" << endl;
						cout << "请输入您想添加的账号身份:" << endl;
						int add_choose_num;
						while (true)
						{
							cin >> add_choose_num;
							if (cin.fail() || add_choose_num < 1 || add_choose_num>2)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "输入错误,请重新输入:" << endl;
								continue;
							}
							break;
						}
						switch (add_choose_num)
						{
							case 1:
							{
								student stu01;
								appointment app01;
								int add_num;
								string add_name;
								int add_password;
								cout << "请输入学生学号:" << endl;
								while (true)
								{
									cin >> add_num;
									if (cin.fail() || add_num < 0)
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								cout << "请输入学生姓名:" << endl;
								while (true)
								{
									cin >> add_name;
									if (cin.fail())
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								cout << "请输入账号密码:" << endl;
								while (true)
								{
									cin >> add_password;
									if (cin.fail() || add_password < 0)
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								stu01.setnum(add_num);
								stu01.setname(add_name);
								stu01.setpassword(add_password);
								stu01.setappointment(app01);
								data.v_student.push_back(stu01);
								break;
							}
							case 2:
							{
								teacher tea01;
								string add_name;
								int add_password;
								cout << "请输入老师姓名:" << endl;
								while (true)
								{
									cin >> add_name;
									if (cin.fail())
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								cout << "请输入账号密码:" << endl;
								while (true)
								{
									cin >> add_password;
									if (cin.fail() || add_password < 0)
									{
										cin.clear();
										cin.ignore(10000, '\n');
										cout << "输入错误,请重新输入:" << endl;
										continue;
									}
									break;
								}
								tea01.setname(add_name);
								tea01.setpassword(add_password);
								data.v_teacher.push_back(tea01);
								break;
							}
						}
						system("pause");
						system("cls");
						break;
					}
					case 2:
					{
						cout << "1,学生;2,老师" << endl;
						cout << "请输入您想查看的账号的身份:" << endl;
						int add_choose_num;
						while (true)
						{
							cin >> add_choose_num;
							if (cin.fail() || add_choose_num < 1 || add_choose_num>2)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "输入错误,请重新输入:" << endl;
								continue;
							}
							break;
						}
						switch (add_choose_num)
						{
							case 1:
							{
								for (auto& temp_stu : data.v_student)
								{
									cout << " 学号: " << temp_stu.getnum() << " 姓名: " << temp_stu.getname() << " 密码: " << temp_stu.getpassword() << endl;
								}
								break;
							}
							case 2:
							{
								for (auto& temp_tea : data.v_teacher)
								{
									cout << " 姓名: " << temp_tea.getname() << " 密码: " << temp_tea.getpassword() << endl;
								}
								break;
							}
						}
						system("pause");
						system("cls");
						break;
					}
					case 3:
					{
						cout << "请输入您想新增的机房的容量:" << endl;
						int room_capacity;
						while (true)
						{
							cin >> room_capacity;
							if (cin.fail() || room_capacity < 1)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "输入错误,请重新输入:" << endl;
								continue;
							}
							break;
						}
						vector<int>temp_room;
						temp_room.resize(room_capacity);
						room0.room.push_back(temp_room);
						cout << "机房添加成功" << endl;
						system("pause");
						system("cls");
						break;
					}
					case 4:
					{
						cout << "目前系统中有" << room0.room.size() << "个机房" << endl;
						cout << "具体信息如下:" << endl;
						for (int h = 0;h != room0.room.size();h++)
						{
							cout << h + 1 << "号机房: " << " 容量 " << room0.room[h].capacity() << endl;
						}
						system("pause");
						system("cls");
						break;
					}
					case 5:
					{
						cout << "是否清空所有预约" << endl;
						cout << "1,是;2,否" << endl;
						int temp_clear_num;
						cout << "请输入您的选择:" << endl;
						while (true)
						{
							cin >> temp_clear_num;
							if (cin.fail() || temp_clear_num < 1 || temp_clear_num>2)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "输入错误,请重新输入:" << endl;
								continue;
							}
							break;
						}
						if (temp_clear_num == 1)
						{
							for (auto& stu : data.v_student)
							{
								if (stu.getappointment().getappointment_status() != "")
								{
									stu.getappointment().setappointment_status(0);
								}
							}
						}
						system("pause");
						system("cls");
						break;
					}
					case 0:
					{
						cout << "是否退出当前的管理员登录" << endl;
						cout << "若是请输入1,若否请输入2" << endl;
						int temp_out_num;
						while (true)
						{
							cin >> temp_out_num;
							if (cin.fail() || temp_out_num < 1 || temp_out_num>2)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "输入错误,请重新输入:" << endl;
								continue;
							}
							break;
						}
						if (temp_out_num == 1)
						{
							cout << "已成功退出登录" << endl;
							system("pause");
							system("cls");
							return;
						}
						system("pause");
						system("cls");
						break;
					}
				}
			}

		}
		if (temp_num == 0)
		{
			cout << "输入错误，登录失败" << endl;
		}
		temp_num = 0;
		system("pause");
		system("cls");
	}
};
class systemWork
{
public:
	void systemwork(systemData& data,com_room& room0)
	{
		for (int m = 0;;m++)
		{
			data.menu01.main_menu();
			int choose;
			while (true)
			{
				cin >> choose;
				if (cin.fail() || choose < 0 || choose>3)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误,请重新输入:" << endl;
					continue;
				}
				break;
			}
			switch (choose)
			{
				case 1:
				{
					studentWork studentwork;
					studentwork.loginstudent_work(data, room0);
					break;
				}
				case 2:
				{
					teacherWork teacherwork;
					teacherwork.loginteacher_work(data, room0);
					break;
				}
				case 3:
				{
					administratorWork administratorwork;
					administratorwork.loginadministrator_work(data, room0);
					break;
				}
				case 0:
				{
					cout << "是否退出机房预约系统" << endl;
					cout << "1,是;2,否" << endl;
					int out_num;
					cin >> out_num;
					if (out_num == 1)
					{
						cout << "感谢使用机房预约系统,欢迎下次使用!" << endl;
						system("pause");
						return;
					}
					break;
				}
			}
		}
	}

};
void test01()
{
	systemData data;
	com_room room0;
	systemWork systemwork01;
	systemwork01.systemwork(data, room0);
}
int main()
{
	test01();
	system("pause");
	return 0;
}