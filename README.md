# cài đặt hệ thống infotainment trên ô tô
Tác giả: Hoàng Văn Hậu.

TimeLine: 27/10/2022 - 5/11/2022

Email: hoanghau290698@gmail.com

Chương trình được viết trên IDE: Microsoft Visual Studio Community 2022

 Kiến thức sử dụng dể hoàn thành dự án:
 
- Cấu trúc dữ liệu dạng cây nhị phân
- Con trỏ 
- Hàm, tham trị, tham chiếu
- Các tính chất của hướng đối tượng
- Nhập xuất
- Sử dụng regex để validate dữ liệu
- Kiểm soát ngoại lệ (exception handling)
- Thao tác đọc ghi file (fstream/ifstream/ofstream)
- Lập trình khái quát (generic programming)


Mô tả chung về chương trình:	
	Chương trình cài đặt và quản lý cơ sở dữ liệu các thông số của xe ô tô trước khi xuất xưởng để bán.
	
Chương trình sẽ bao gồm các chức năng cơ bản như sau:
	
1. Nhập thông tin cài đặt của các chức năng: Display, Sound, General
	Cụ thể như sau:Tên xe, mã số cá nhân, email người sử dụng(Định dạng email là emai@abc.xyz), ODO, thông tin km cần đến để bảo dưỡng xe.
	
  	- Display: light level, screen light level, taplo light level.
 	- Sound: Media volume level, Call volume level, Navigation volume level, Notification volume level.
  	- General: Cài đặt timezone và cài đặt ngôn ngữ.
	- Dữ liệu timezone (từ file timezones.txt), language (từ file languages.txt) phải sắp xếp theo Anphabet, hiển 
	- Các chức năng không được cài đặt sẽ nhận giá trị khởi tạo ban đầu
	-Với mỗi hàm nhập sẽ thực hiện kiểm soát ngoại lệ để đảm bảo dữ liệu nhập đúng đắn
	
2. Xuất thông tin cài đặt của từng chức năng: Display, Sound, General
	
3. Xuất thông tin toàn bộ về xe :
	+ khi xuất thông tin: 
		- được sắp xếp theo mã số cá nhân hoặc tên chủ xe dựa theo lựa chọn của người dùng  
		- Với hàm đọc/ghi file cần kiểm soát ngoại lệ để đảm bảo việc đọc ghi file không xảy ra lỗi
		- với chức năng General. Nếu không tìm thấy thì lưu dữ liệu mặc định ra file tương ứng.
		- Dữ liệu các xe sẽ được lưu trữ và cập nhật lại
