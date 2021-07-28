library IEEE;
use IEEE.std_logic_1164.all;
entity full_adder is
port(
a : in std_logic;
b : in std_logic;
cin : in std_logic;
s : out std_logic;
cout : out std_logic);
end full_adder;
architecture rt1 of full_adder is begin
process(a,b,cin) is
begin
 s <= a xor b xor cin;
 cout <=  ( a and b )  or (( a xor b )and cin);
end process;
end rt1;