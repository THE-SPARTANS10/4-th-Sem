------------------------------------------FULL ADDER
library IEEE;
use IEEE.std_logic_1164.all;
entity full_adder is
port(
	a,b,cin : in std_logic;
    s,cout : out std_logic);
end full_adder;

architecture Part1 of full_adder is
begin
	s <= a xor b xor cin;
 	cout <=  ( a and b )  or (( a xor b )and cin);
end Part1;
------------------------------------------PARALLEL ADDER
library IEEE;
use IEEE.std_logic_1164.all;
entity parallel_adder is
port(
	PA,PB : in std_logic_vector(3 downto 0);
    PCIN : in std_logic;
    PS : out std_logic_vector(3 downto 0);
    PC : out std_logic);
end parallel_adder;

architecture Part2 of parallel_adder is
component full_adder is
port(
	a,b,cin : in std_logic;
    s,cout : out std_logic);
end component;

signal c1,c2,c3 : std_logic;
begin

	FA0: full_adder port map(PA(0),PB(0),PCIN,PS(0),c1);
    FA1: full_adder port map(PA(1),PB(1),c1,PS(1),c2);
    FA2: full_adder port map(PA(2),PB(2),c2,PS(2),c3);
    FA3: full_adder port map(PA(3),PB(3),c3,PS(3),PC);
    
end Part2;
