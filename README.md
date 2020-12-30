# netwhat

### 1. IP address <br>
- 네트워킹이 가능한 장비를 `식별`하는 주소.
- 네트워킹을 하는 장비들에게 숫자 12개의 고유한 주소를 주어 서로를 인식하고 통신하도록 하자.- 라는 의미의 통신규약(protocol)이 존재한다.

### 2. Netmask

### 3. Subnet of an IP with Netmask

### 4. Broadcast address of a subnet

### 5. Different ways to represent an ip address with the Netmask

### 6. Public IPs V.S Private IPs

### 7. Class of IP addresses <br>
- **하나의 IP주소에서 네트워크 영역과 호스트 영역을 나누는 방법이자, 약속.**
- 네트워크 크기에 따른 구분이라 생각하자.
- 하나의 네트워크에서 몇개의 호스트 IP까지 가질 수 있는가에 따라서 클래스를 나눈다.
	1. A Class
		- 0XXX XXXX. XXXX XXXX. XXXX XXXX. XXXX XXXX <br>
			-> **2진수로 표현 시 맨 앞의 수가 0인 경우.** <br>
			-> 10진수로 표현 시 0.0.0.0 ~ 127.255.255.255 <br>
			-> 그렇지만 **1.0.0.0 ~ 126.0.0.0** 까지로 규정. <br>
					- `네트워크 영역.호스트영역.호스트영역.호스트영역` <br>
					- 호스트 주소가 가질 수 있는 갯수 : 2^24 - 2 <br>
					- 0.0.0 과 255.255.255는 각각 `네트워크 주소`와 `브로드캐스트 주소`로 사용되기 때문에 호스트 IP로 사용하면 안되기 때문에 빼줘야 된다.

	2. B class
		- 10XX XXXX. XXXX XXXX. XXXX XXXX. XXXX XXXX <br>
			-> **2진수로 표현 시 맨 앞의 두 수가 10인 경우** <br>
			-> 10진수로 표현 시 128.0.0.0 ~ 191.255.255.255 <br>
				- `네트워크 영역.네트워크 영역. 호스트 영역. 호스트 영역` <br>
				- 호스트 주소가 가질 수 있는 갯수 : 2^16 - 2 <br>



### 8. TCP

### 9. UDP

### 10. Network layers

### 11. OSI model

### 12. DHCP server and the DHCP protocol

### 13. DNS server and the DNS protocol

### 14. The rules to make 2 devices communicate using IP addresses

### 15. How does routing work with IP

### 16. Default gateway for routing

### 17. Port from an IP point of view and what it is used for when connecting to another device

