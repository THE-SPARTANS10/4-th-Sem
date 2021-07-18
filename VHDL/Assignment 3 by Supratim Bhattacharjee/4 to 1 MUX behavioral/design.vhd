library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
port(
  s1 : in std_logic;
  s0 : in std_logic;
  i0 : in std_logic;
  i1 : in std_logic;
  i2 : in std_logic;
  i3 : in std_logic;
  y : out std_logic);
end mux41;

architecture behavioral of mux41 is
begin
  process(s1,s0,i0,i1,i2,i3)
  begin
    if(s1='0' and s0='0') then
      y<=i0;
    elsif(s1='0' and s0='1') then
      y<=i1;
    elsif(s1='1' and s0='0') then
      y<=i2;
    else
      y<=i3;
    end if;
  end process;
end behavioral;