# OOP_Summer_Fsoft_Test
## I. Yêu cầu 1
1. Tạo môt lớp abstract (thuần ảo) NhanVien có cac thông tin sau (02 Điểm)
  - Mã số nhân viên
  - Họ và Tên
  - Tên bộ phận
  - Job title(Có kiểu dữ liệu là enum JobTitle(Developer, Tester, Manager)  
  Trong lớp này có các method
  - ShowInformation(): hiển thị mã số nhân viên, họ tên, tên bộ phận
  - void DisplayDailyWork() = 0;
2. Tạo lớp Developer kế thừa từ lớp NhanVien, các biến (instance) của lớp này có job title là JobTitle.Developer. (01 Điểm) 
Lớp này thêm thông tin: 5. Dự án đang làm 
  Lớp Developer này có method sau:  
    - ShowInformation: hiển thị mã số nhân viên, họ tên, tên bộ phận, Tên dự án đang làm
3. Tạo lớp Manager kế thừa từ lớp NhanVien, các biến (instance) của lớp này có job title là JobTitle.Manager. (01 Điểm) 
  Lớp Manager này thêm thông tin: Tên khách hàng mà Manager đang quản lý  
  Lớp Manager này có method sau:  
    a. ShowInformation: hiển thị mã số nhân viên, họ tên, tên bộ phận, Tên khách hàng mà Manager đang quản lý 
## II. Yêu cầu 2: Viết môt chương trình dựa trên các class đã tạo từ yêu cầu I như sau  
  1. Load 1 file danh sách sinh viên từ ngoài vào (txt) và sau đó thực hiện xắp xếp theo tên sinh viên rồi in ra phàn hình (01 Điểm)  
  2. Cho phép người dùng add thêm thông tin vào danh sách này (01 Điểm) 
  3. Cho phép người dùng xoá 1 nhân viên bất kỳ, mà số nhân viên của nhân viên nay do người
  dùng nhập vào (01 Điểm) 
  3.1 Dùng smart pointer cho các hành động add/xóa (01 Điểm)  
  4. Cài đặt chức năng săp xếp list nhân viện theo thứ tự tăng dần của Mã Nhân viên, rồi in thông
  tin của tất cả các nhiên viên trong list(bằng cách gọi hàm ShowInformation()). (01 Điểm)  
  5. Cho người dùng nhập vào mã nhân viên --> In ra thông tin của nhân viên đó (gọi hàm ShowInformation() để in thông tin) (01 Điểm)  
## Estimate time: 01 days 
