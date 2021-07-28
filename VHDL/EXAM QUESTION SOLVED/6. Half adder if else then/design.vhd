library IEEE;
use IEEE.std_logic_1164.all;
entity half_adder is
port(
a : in std_logic;
b : in std_logic;
c : out std_logic;
s : out std_logic);
end half_adder;
architecture rt1 of half_adder is begin
process(a,b) is
begin
  if(a='0' and b='0')
     then s<='0';c<='0';
  elsif(a='0' and b='1')
     then s<='1';c<='0';
  elsif(a='1' and b='0')
     then s<='1';c<='0';
  elsif(a='1' and b='1')
     then s<='0';c<='1';
   end if;
end process;
end rt1;