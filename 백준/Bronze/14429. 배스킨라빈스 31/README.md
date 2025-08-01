# [Bronze I] 배스킨라빈스 31 - 14429 

[문제 링크](https://www.acmicpc.net/problem/14429) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 구현, 게임 이론

### 제출 일자

2025년 7월 30일 15:29:00

### 문제 설명

<p>수련회 첫 날 밤을 맞아 유진이와 규용이는 배스킨라빈스 31 게임으로 진 사람을 정해 간장을 마시려고 한다. 게임의 룰은 다음과 같다.</p>

<p>유진이와 규용이는 한 줄로 나란히 앉아있다. 맨 왼쪽에는 유진이가 앉는다.</p>

<p>게임은 유진이부터 시작하여 오른쪽으로 진행한다.</p>

<p>자기 차례가 되면 1부터 j사이의 자연수를 1~m개 연달아 말할 수 있다. 무조건 1개 이상 말해야 한다.</p>

<p>j를 말하는 사람이 진다.</p>

<p>게임을 몇 번이나 해 보았지만 유진이만 계속 간장을 먹었다. 화가 난 유진이는 인터넷을 검색해 반드시 이길 수 있는 승리 전략을 찾았다. 승리 전략은 이러하다.</p>

<ul>
	<li>전체 개수 j-1을 1+m으로 나누어 나머지 r을 구한다.</li>
	<li>전체의 숫자 중 r번째의 숫자가 필승 숫자의 초항이다.</li>
	<li>초항부터 1+m을 계속 더해 가면 그것이 곧 필승 숫자들이다.</li>
	<li>게임을 시작하면 무조건 필승 숫자의 초항까지 말한다.</li>
	<li>상대가 몇 개를 말하던 다음 턴에 자신이 필승 숫자를 포함해 말해나가면 게임에서 이기게 된다.</li>
	<li>예) 31을 말하면 지는 게임에서 한 턴에 1~3번까지 말할 수 있다면 (31-1)÷4=7...2 이므로 필승 숫자는 2, 6, 10, 14, 18, 22…가 된다.</li>
</ul>

<p>‘다음의 승리 전략을 이용’하여 유진이가 게임에서 이기는 최소 턴의 수를 길이라고 할 때, n번의 게임 후에 길이가 가장 짧은 게임의 번호와 길이를 구하시오.</p>

### 입력 

 <p>첫째 줄에 플레이할 게임의 판 수 n(1 ≤ n ≤ 1,000)이 주어진다. 다음 줄에는 전체 개수이자 말하면 지는 숫자 j(1 ≤ j ≤ 10,000)와 한 턴에 말할 수 있는 최대 자연수의 개수 m(1 ≤ m ≤ 9,999)이 공백으로 분리되어 주어진다. 단, 항상 j>m이며 j-1은 m+1의 배수가 아니다. 즉, 유진이는 항상 게임에서 이길 수 있다</p>

### 출력 

 <p>길이가 가장 짧은 게임의 번호와 길이를 출력한다. 만약 길이가 가장 짧은 게임이 두 개 이상일 경우 가장 먼저 입력된 번호와 그 길이를 출력한다.</p>

