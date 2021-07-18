library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
port(
  x : in std_logic;
  y : in std_logic;
  z : in std_logic;
  s : out std_logic;
  c : out std_logic);
end full_adder;

architecture behavioral of full_adder is
begin
  process(x,y,z)
  begin
    if(x='0' and y='0' and z='0') then
      s<='0';
      c<='0';
    elsif(x='0' and y='0' and z='1') then
      s<='1';
      c<='0';
    elsif(x='0' and y='1' and z='0') then
      s<='1';
      c<='0';
    elsif(x='0' and y='1' and z='1') then
      s<='0';
      c<='1';
    elsif(x='1' and y='0' and z='0') then
      s<='1';
      c<='0';
    elsif(x='1' and y='0' and z='1') then
      s<='0';
      c<='1';
    elsif(x='1' and y='1' and z='0') then
      s<='0';
      c<='1';
    else
      s<='1';
      c<='1';
    end if;
  end process;
end behavioral;