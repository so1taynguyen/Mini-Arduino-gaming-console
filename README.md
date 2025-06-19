<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![Unlicense License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Mục lục</summary>
  <ol>
    <li>
      <a href="#giới-thiệu-về-dự-án">Giới thiệu về Dự án</a>
	  <ul>
        <li><a href="#các-tính-năng-chính">Các tính năng chính</a></li>
		<li><a href="#các-thành-phần-của-dự-án">Các thành phần của Dự án</a></li>
		<li><a href="#kiến-trúc-dự-án">Kiến trúc Dự án</a></li>
      </ul>
    </li>
    <li>
      <a href="#bắt-đầu">Bắt đầu</a>
      <ul>
        <li><a href="#yêu-cầu-cần-thiết">Yêu cầu cần thiết</a></li>
        <li><a href="#cài-đặt">Cài đặt</a></li>
      </ul>
    </li>
    <li><a href="#cách-chạy">Cách chạy</a></li>
    <li><a href="#thành-tựu">Thành tựu</a></li>
    <li><a href="#đóng-góp">Đóng góp</a></li>
    <li><a href="#liên-hệ">Liên hệ</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## Giới thiệu về Dự án

Dự án này là một Mini Arduino Gaming Console được triển khai trên vi điều khiển Arduino. Dự án bao gồm ba trò chơi cổ điển: Flappy Bird, Ping Pong, và Hungry Snake, với kế hoạch tích hợp thêm trò Tetris (hiện tại bị comment trong mã nguồn). Mục tiêu của dự án là mang lại trải nghiệm chơi game đơn giản, thú vị, đồng thời thể hiện khả năng lập trình nhúng và thiết kế giao diện người dùng trên phần cứng hạn chế.

Dự án sử dụng Arduino để điều khiển màn hình, xử lý đầu vào từ các nút bấm, và quản lý logic trò chơi. Điểm số cao nhất của mỗi trò chơi được lưu trữ trong bộ nhớ EEPROM để đảm bảo dữ liệu bền vững. Ngoài ra, dự án có tiềm năng mở rộng với các tính năng như âm thanh (hiện bị vô hiệu hóa do nhiễu từ loa) và giao diện menu thân thiện.

![result](./images/Result.gif)

<p align="right">(<a href="#readme-top">Back to top</a>)</p>

### Các tính năng chính

* __Ba trò chơi cổ điển__: Flappy Bird, Ping Pong, Hungry Snake.
* __Giao diện đồ họa__: Sử dụng màn hình ILI9341 để hiển thị đồ họa 2D đơn giản, bao gồm các sprite, văn bản, và màu sắc tùy chỉnh.
* __Lưu trữ điểm cao__: Sử dụng EEPROM để lưu điểm số cao nhất cho từng trò chơi.
* __Điều khiển bằng nút bấm__: Năm nút bấm (Lên, Xuống, Trái, Phải, Giữa) để điều hướng menu và chơi game.
* __Menu chọn trò chơi__: Giao diện menu cho phép người dùng chọn giữa các trò chơi bằng nút Lên/Xuống và xác nhận bằng nút Giữa.
* __Hỗ trợ âm thanh (tùy chọn)__: Mã nguồn bao gồm định nghĩa giai điệu cho Snake và Ping Pong, nhưng hiện bị vô hiệu hóa do nhiễu loa.
* __Khả năng mở rộng__: Mã nguồn được tổ chức modular, dễ dàng thêm trò chơi mới hoặc cải tiến tính năng.

<p align="right">(<a href="#readme-top">Back to top</a>)</p>

### Các thành phần của Dự án

* __Source Phần mềm__
    * [main.ino](./Software/main/main.ino): File chính điều phối toàn bộ chương trình, bao gồm khởi tạo phần cứng, menu chọn trò chơi, và vòng lặp chính để chạy các trò chơi.
    * [Thư mục Flappy Bird](./Software/main/Flappy_bird/), [Thư mục Snake Game](./Software/main/Snake_game/), [Thư mục Ping Pong](./Software/main/Ping_pong/), (Pending) [Thư mục Tetris](./Software/main/Tetris/).
* __Source Phần cứng__
    * __Vi điều khiển Arduino__: Xử lý logic trò chơi và giao tiếp với các thiết bị ngoại vi.
    * __Màn hình ILI9341__: Hiển thị đồ họa 240x320 pixel, sử dụng thư viện [ILI9341_Fast](./Library/Fast_ILI9341_Library/).
    * __EEPROM AT24C256__: Lưu trữ điểm số cao nhất, sử dụng thư viện [AT24C](./Library/AT24C/).
    * __Nút bấm__: Năm nút bấm (pin 2, 3, 4, 5, 7) để điều khiển.
    * __Loa (tùy chọn)__: Pin 6 để phát âm thanh, nhưng hiện bị vô hiệu hóa.

<p align="right">(<a href="#readme-top">Back to top</a>)</p>

### Kiến trúc Dự án

#### Kiến trúc tổng quan

![diagram](./images/Block_diagram.png)

<p align="right">(<a href="#readme-top">Back to top</a>)</p>

![bottom](./images/Bottom_layer.png)

![flappy](./images/Flappy_flow_chart.png)

![irl_bottom](./images/IRL_bottom_layer.png)

![irl_top](./images/IRL_top_layer.png)

![pcb](./images/PCB_layout.png)

![pingpong](./images/PingPong_flow_chart.png)

![schematic](./images/Schematic.png)

![snake](./images/Snake_flow_chart.png)

![top](./images/Top_layer.png)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/so1taynguyen/Mini-Arduino-gaming-console/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/so1taynguyen/Simple-MIPS32-Hardware-Implementation-with-Python-Assembler.svg?style=for-the-badge
[forks-url]: https://github.com/so1taynguyen/Mini-Arduino-gaming-console/network/members
[stars-shield]: https://img.shields.io/github/stars/so1taynguyen/Simple-MIPS32-Hardware-Implementation-with-Python-Assembler.svg?style=for-the-badge
[stars-url]: https://github.com/so1taynguyen/Mini-Arduino-gaming-console/stargazers
[issues-shield]: https://img.shields.io/github/issues/so1taynguyen/Simple-MIPS32-Hardware-Implementation-with-Python-Assembler.svg?style=for-the-badge
[issues-url]: https://github.com/so1taynguyen/Mini-Arduino-gaming-console/issues
[license-shield]: https://img.shields.io/github/license/so1taynguyen/Simple-MIPS32-Hardware-Implementation-with-Python-Assembler.svg?style=for-the-badge
[license-url]: https://github.com/so1taynguyen/Mini-Arduino-gaming-console/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/linkk-isme/