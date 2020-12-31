# netwhat

### 1. IP address <br>
- 네트워킹이 가능한 장비를 `식별`하는 주소.
- 네트워킹을 하는 장비들에게 숫자 12개의 고유한 주소를 주어 서로를 인식하고 통신하도록 하자.- 라는 의미의 통신규약(protocol)이 존재한다.
__

### 2. Netmask <br>
- 네트워크 주소 부분의 비트를 1로 치환한 것이 넷마스크이다.
- IP 주소와 넷마스크를 AND연산을 하면 네트워크 주소를 얻을 수 있다.
	- `1100 1011. 0000 0000. 0111 0111. 0010 1011(203.0.113.43)` - IP 주소
	- `1111 1111. 1111 1111. 1111 1111. 0000 0000(255.255.255.0)` - 넷마스크
	- AND 연산(둘다 1일 때만 1)을 하면 네트워크 주소를 얻는다.필요가 없는지를 알게 된다.
	- 라우터는 서브넷 마스크를 봄으로써 어떤 비트를 참조해야 하는지 또는 참조할 
	- 마스크는 단순히 라우터가 참조해야할 비트가 어느 것인지를 말해주는 일종의 필터 
		- 2진수 마스크에서 한 번호가 1 이라면 보고, 0이라면 볼 필요가 없다는 것을 의미해주기 때문에 라우터가 32비트 주소 전체를 처리해야 하는 부담을 줄여주며, 단순히 마스크에 의해 선택된 비트들만 보도록 해준다.
- 255.255.255.0 에선 정책상도 C클래스이고, C클래스 최대크기를 포괄하므로 서브넷 마스크가 아닌 넷마스크이다.(확실치 않음)

- IPv4 초창기 시절 A, B, C 급으로 (고정크기 8, 16, 24 bit mask) network을 나눠 썼는데, 좀 비효울 적이어서 CIRD 후 큰 network address 를 쪼개면서 subnet mask 가 생겨났다.(가변 크기(1~32)bit mask가 가능하도록)
	- 이제와서는 netmask, subnet mast의 구분이 사라진 것 같다.

### 3. Subnet of an IP with Netmask <br>
##### Default subnet mask
- IP를 클래스로 나눈다는 뜻 : 서브넷 마스크를 사용한다는 말과 같은 의미다.
- 별개의 서브넷 마스크를 생성하지 않아도 기본적으로 적용되어 있는게 기본 서브넷 마스크. 
- 기본 서브넷 마스크로 쪼개진 네트워크 주소를 서브넷 네트워크라고 한다.
- 내가 이해한 바:
   	```서브넷 마스크라는 것은 넷마스크랑 기능적으로 같이, 네트워크를 쪼개서 네트워크 주소 부분을 1로 치환하여 AND 연산에 활용할 수 있도록 만들어 진것. 
	- 이 때, 예전에는 넷마스크가 클래스로 나뉘어진 네트워크 주소 부분을 모두 포괄하고 있다면(쪼갠 부분이 하필이면 클래스를 나눈 부분일 때) 이를 넷마스크라고 하고, 클래스로 나뉘어진 부분과 일치하지 않는다면 이를 서브넷 마스크(1~32bit 가변)라고 불렀지만 지금 모호해진 결과 넷마스크를 기본 서브넷 마스크(default subnet mask)라고 여기 필자는 말하고 있는 것 같다.
	```
##### subnetting
- 한 개의 네트워크를 서브넷 마스크를 이용해 여러 개의 `서브넷 네트워크`로 분할 하는 것.
- 왜 하나의 네트워크를 여러개로 나눠야 할까?
	- 네트워크 자원을 효율적으로 사용하기 위해서.
	- IP를 사용하는 네트워크 장치들의 수에 따라 효율적으로 사용할 수 있도록 하는 방법이 서브넷팅.
		- 반대로 네트워크를 합쳐 네트워크를 확장하는 슈퍼넷팅이라는 개념도 존재.
- 서브넷 마스크를 이용 -> Host ID 를 Network ID로 변환.
- 슈퍼넷팅은 서브넷 마스크를 이용 -> Network ID를 Host ID로 변환하게 되어 가능해짐
- 즉, **서브넷팅은 네트워크 주소부분의 비트를 연장하고, 그 나머지 호스트 부분이 호스트 식별자가 된다.**
	- example: A클래스 IP주소(1.1.1.1)의 기본 서브넷 마스크(255.0.0.0)를 B클래스의 서브넷 마스크(255.255.0.0)로 변경하는 예시를 생각해보면 된다.
	- 변경된 서브넷 마스크로 AND 연산 -> 네트워크 ID가 기존의 1.0.0.0 에서 1.1.0.0 으로 확장.
	- 반대로 호스트 ID의 범위는 256 * 256으로 훨씬 적어짐.
- **서브넷팅으로 Network ID 가 확장 -> 할당 가능한 네트워크의 수가 증가.**
	- 하지만 네트워크가 분리됨 -> 서로가 통신하기 위해선 라우터를 통하여서만 가능
	- 물론 각 네트워크에 소갸해 있는 호스트들은 같은 영역에 존재 -> 라우터까지 거치지 않고 통신 가능.
- **특정 호스트에서 너무 많은 트래픽을 발생시켜서 속도를 저하시키는 문제를 해결.**
	- 네트워크 분리 -> 브로트캐스트 도메인의 크기가 줄어듦(브로드캐스트 주소가 다양해짐)
		- 한 브로드캐스트 주소를 너무 많은 호스트가 갖는 걸 방지 -> 트래픽 문제 해결.
	- > 서브넷의 브로드캐스트 주소란 : 255보다 후러씬 작은수를 가질 수 있다.

### 4. Broadcast address of a subnet <br>
- 특정 네트워크에 속하는 모든 호스트들이 갖게 되는 주소.
- 네트워크에 있는 모든 클라이언트 모두에게 데이터를 보내기 위함.
- 해당 네트워크에 속하는 모든 IP 주소 가운데 **맨 마지막 IP 주소**
	- 계산 방법: 서브넷 마스크의 '0' 인 부분을 모두 1로 바꾼다.
		- C클래스 IP - 192.168.2.0 이라고 한다면 브로드캐스트 주소는 `192.168.2.255` 가 된다.

### 5. Different ways to represent an ip address with the Netmask

### 6. Public IPs V.S Private IPs <br>
#### 6-1. Public IP
- 인터넷 사용자의 로컬 네트워크를 식별하기 위해 ISP(인터넷 서비스 공급자)가 제공하는 IP 주소.
- 전 세계에서 유일한 IP주소를 갖는다.
- 공인 IP주소가 외부에 공개 -> 인터넷에 연결된 다른 PC로부터의 접근이 가능.
	- 방화벽 등의 보안 프로그램을 설치할 필요가 있다.

#### 6-2. Private IP
- 일반 가정, 회사 내 등에 할당된 IP주소, 로컬 || 가상 IP 라고도 한다.
- IPv4의 주소 부족으로 인해 서브넷팅된 IP이기 때문에 라우터에 의해 로컬 네트워크상의 PC 나 장치에 할당.
- 사설 IP 주소대역
	- Class A : 10.0.0.0 ~ 10.255.255.255
	- Class B : 172.16.0.0 ~ 172.31.255.255
	- Class C : 192.168.0.0 ~ 192.168.255.255

	![사설 IP와 공인 IP의 차이](https://media.discordapp.net/attachments/790600784110813264/794120515445981194/2020-12-31_5.31.06.png)
	- **사설 IP 주소만으로는 인터넷에 직접 연결할 수 없다.**
	- **라우터를 통해 1개의 공인 (Public) IP만 할당하고, 라우터에 연결된 개인 PC는 사설 (Private) IP를 각각 할당 받아 인터넷에 접속 할 수 있게 된다.** <br>
	![사설 IP와 공인 IP가 작동하기 위한 방식](https://media.discordapp.net/attachments/790600784110813264/794122748947070996/2020-12-31_5.39.49.png)

	- **추가: 고정 IP와 유동 IP**
		- 고정 IP: 컴퓨터에 고정적으로 부여된 IP. 한번 부여되면 IP를 반납하기 전까지 다른 장비에 부여 X
		- 유동 IP: 컴퓨터를 사용할 때 남아있는 IP 중에서 돌아가면서 부여하는 IP.

		- **인터넷 상에서 서버를 운영하고자 할 때는 공인(Private)IP를 고정 IP로 부여해야 한다는 것이 중요**
			- 공인 IP:  다른 사람이 내 서버에 접속 할 수 있도록 한다.
			- 고정 IP: 내 서버에서만 접속이 될 수 있도록 한다.
		- **가정 집에선 ISP에서 각 가정마다 공인 IP를 유동 IP로 부여하고, 공유기 내부에서는 사설 IP를 유동 IP로 부여하는 것이 일반적이라고 보면 될 것.**

### 7. Class of IP addresses <br>
- **하나의 IP주소에서 네트워크 영역과 호스트 영역을 나누는 방법이자, 약속.**
- 네트워크 크기에 따른 구분이라 생각하자.
- 하나의 네트워크에서 몇개의 호스트 IP까지 가질 수 있는가에 따라서 클래스를 나눈다.

	1. A Class
		- 0XXX XXXX. XXXX XXXX. XXXX XXXX. XXXX XXXX <br>
			- **2진수로 표현 시 맨 앞의 수가 0인 경우.** <br>
			- 10진수로 표현 시 0.0.0.0 ~ 127.255.255.255 <br>
			- 그렇지만 **1.0.0.0 ~ 126.0.0.0** 까지로 규정. <br>
			&emsp; - `네트워크 영역.호스트영역.호스트영역.호스트영역` <br>
			&emsp; - 호스트 주소가 가질 수 있는 갯수 : **2^24 - 2** <br>
					- 0.0.0 과 255.255.255는 각각 `네트워크 주소`와 `브로드캐스트 주소`로 사용되기 때문에 호스트 IP로 사용하면 안되기 때문에 빼줘야 된다. <br>

	2. B class
		- 10XX XXXX. XXXX XXXX. XXXX XXXX. XXXX XXXX <br>
			- **2진수로 표현 시 맨 앞의 두 수가 10인 경우** <br>
			- 10진수로 표현 시 128.0.0.0 ~ 191.255.255.255 <br>
			&emsp; - `네트워크 영역.네트워크 영역. 호스트 영역. 호스트 영역` <br>
			&emsp - 호스트 주소가 가질 수 있는 갯수 : **2^16 - 2** <br>

	3. C class
		- 110X XXXX. XXXX XXXX. XXXX XXXX. XXXX XXXX <br>
			- **2진수로 표현 시 맨 앞의 3개의 수가 110 인 경우.** <br>
			- 10진수로 표현 시 192.0.0.0 ~ 223.255.255.255 <br>
			&emsp; - `네트워크.네트워크.네트워크.호스트` <br>
			&emsp; - 호스트 주소가 가질 수 있는 갯수 : **2^8 - 2** <br>

	4. D & E class
		- D : 멀티캐스트용
			- 224.0.0.0 ~ 239.255.255.255 <br>

		- E : 연구용
			- 240.0.0.0 ~ 255.255.255.255 <br>


### 8. TCP
- TCP/IP : 인터넷 프로토콜 중 가장 중요한 역할을 하는 `TCP` 와 `IP` 의 합성어
	- 데이터의 흐름관리, 정확성 확인, 패킷의 목적지 보장을 담당.
	- **데이터의 정확성 확인은 TCP가, 패킷을 목적지까지 전송하는 일은 IP가 담당.**
> TCP/IP 의 4계층 <br> TCP/IP 는 OSI 참조모델과 달리 표현계층, 세션계층을 응용계층에 다 포함시키고 있지만, 사실상 TCP/IP Model의 Application 계층 하나에서 Application, Presentation, Session 계층의 구현을 다 하고 있다고 이해하는 게 더 올바르다.
![OSI 7계층과 TCP/IP 4계층 비교](https://media.discordapp.net/attachments/790600784110813264/794186409673883658/2020-12-31_9.53.04.png)
- 데이터가 단계 별로 헤더(Date -> Segment -> Datagram -> Frame)을 붙여 전송하며 이를 **데이터 캡슐화**라고 한다.
![데이터 캡슐화](https://media.discordapp.net/attachments/790600784110813264/794186478787362826/2020-12-31_9.53.26.png)

### 9. UDP
- 

### 10. Network layers <br>
- **네트워크 상에서 여러 대의 컴퓨터가 데이터를 주고 받으려면 서로 연동 가능하도록 표준화된 인터페이스를 지원해야 한다.**
	- OSI 7 모델 && TCP/IP 모델 모두 `계층 구조`를 갖고 있음
- 계층구조는 네트워크 뿐만 아니라 운영체제 등 다양한 분야에서 적용.
- 계층구조를 사용하는 목적은 **분할 정복(Divide and Conquer)** 때문.
	- 복잡한 문제를 해결하고자 할 때, 나누어 생각하면 쉽게 해결할 수 있다는 취지인 것.
- 또 다른 특징으로는 위, 아래 층으로만 이동할 수 있다는 점.
	- 건너뛰어 한번에 맨 위 또는 아래로 갈 수 없다.
	- 다음 단계로 넘어가려면 이전 계층이 `전제 조건`이 되어야 한다.

### 11. OSI model <br>
- **Open System Interconnection**
- 네트워크 통신 과정을 7개의 계층으로 구분한 산업 표준 참조 모델.
- 초창기 네트워크는 컴퓨터마다 시스템이 달랐기 때문에 하드웨어와 소프트웨어의 논리적인 변경없이 통신할 수 있는 표준 모델이 나타남.
- OSI 참조모델은 말 그대로 참조 모델일 뿐, 실제 사용되는 인터넷 프로토콜은 7계층 구조를 완전히 따르지 않음.
- 인터넷 프로토콜 스택(Internet Protocol Stack)은 현재 대부분 TCP/IP를 따른다.
![OSI 7계층 모델](https://media.discordapp.net/attachments/790600784110813264/794167182753923092/2020-12-31_8.36.40.png)

> **PDU란? 각 계층에서 전송되는 단위.**<br> 1계층에서는 PDU가 비트라고 생각하기 쉽지만 PDU라고 하지 않고 여기서 비트는 단위라기 보단, 단지 전기 신호의 흐름일 뿐이다.<br> PDU는 2계층-프레임(Frame), 3계층-패킷(Packet), 4계층-세그먼트(Segment) 만 생각하면 된다. <br> 네트워크 통신과정을 깊게 이해하기 위해서는 왜 각각의 계층의 PDU가 다른 지 알아야 하고, 역할에 대해 알아야 함.

| |계층|Description|PDU|프로토콜|장비
|--|--|--|--|--|--|
|1계층|물리계층(Physical)|OSI모델의 최하위 계층에 속함.<br>상위 계층에서 전송된 데이터를 물리 매체(허브, 라우터, 케이블 등)을 통해 다른 시스템에 전기적 신호를 전송하는 역할을 한다.|비트(bit)|Modem, Cable, Fiber, RS-232C|허브, 리피터|
|2계층|링크계층(Link Layer)|네트워크 기기들 사이의 데이터 전송을 하는 역할을 함.<br>시스템 간의 오류 없는 데이터 전송을 위해 `프레임`으로 구성하여 물리계층으로 전송.<br> 3계층에서 정보를 받아 주소와 제어정보를 헤더와 테일에 추가함.|프레임(Frame)|이더넷, MAC, PPP, ATM, LAN, WiFi|브릿지, 스위치|
|3계층|네트워크계층(Network Layer)|기기에서 데이터그램(Dategram)이 가는 경로를 설정해주는 역할을 한다.<br>라우팅 알고리즘을 사용하여 최적의 경로를 선택하고 송신측으로부터 수신측으로 전송한다.<br>이 때, 전송되는 데이터는 `패킷`단위로 분할하여 전송한 후 다시 합쳐진다.<br>2계층이 노드 대 노드 전달을 감독한다면, 3계층은 각 패킷이 목적지까지 성공적이고 효과적으로 전달되도록 함.|패킷(Packet)|IP, ICMP 등|라우터, L3 스위치|
|4계층|전송계층(Transport Layer)|발신지에서 목적지(End-to-End) 간 제어와 에러를 관리.<br>패킷의 전송이 유효한지 확인하고 전송에 실패된 패킷을 다시 보내는 것과 같은 신뢰성 있는 통신을 보장함.<br>헤드에는 `세그먼트`가 포함됨.<br>주소 설정, 오류 및 흐름 제어, 다중화를 수행함.|세그먼트(Segment)|TCP, UDP, ARP, RTP|게이트웨이, L4 스위치|
|5계층|세션계층(Session Layer)|통신세션을 구성하는 계층으로 `포트(Port)번호`를 기반으로 연결됨.<br>통신장치 간의 상호작용을 설정하고 유지하며 동기화함.<br>동시송수신(Duplex), 반이중(Half-Duplex), 전이중(Full-Duplex) 방식의 통신과 함께 체크 포인팅과 유후, 종료, 다시 시작 과정들을 수행함.||NetBIOS, SSH, TLS||
|6계층|표현계층(Presentation Layer)|송신측과 수신측 사이에서 `데이터 형식(png, jpg, jpeg...)`을 정해줌.<br>받은 데이터를 코드 변환, 구문 검색, 암호화, 압축의 과정을 통해 올바른 표준 방식으로 변환해줌.||JPG, MPEG, SMB, AFP||
|7계층|응용계층(Application Layer)|사용자와 바로 연결되어 있으며 응용 SW를 도와주는 계층.<br>사용자로부터 정보를 입력받아 하위계층으로 전달.<br>하위계층에서 전송한 데이터를 사용자에게 전달함.<br>파일전송, DB, 메일 전송 등 여러가지 응용 서비스를 네트워크에 연결해주는 역할을 한다.||DHCP, DNS, FTP, HTTP|

![TCP/IP 와 OSI Model의 계층 설명 및 비교](https://media.discordapp.net/attachments/790600784110813264/794187606220472320/2020-12-31_9.57.42.png)
<br>
[무조건 봐야하는 참고자료](http://blog.naver.com/PostView.nhn?blogId=demonicws&logNo=40117378644)

### 12. DHCP server and the DHCP protocol

### 13. DNS server and the DNS protocol

### 14. The rules to make 2 devices communicate using IP addresses

### 15. How does routing work with IP

### 16. Default gateway for routing

### 17. Port from an IP point of view and what it is used for when connecting to another device

