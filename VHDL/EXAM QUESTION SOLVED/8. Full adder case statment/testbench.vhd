library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

--DUT Component
component full_adder is
port(
  a : in std_logic_vector(2 downto 0);
  s : out std_logic_vector(1 downto 0));
end component;
 
signal a_in: std_logic_vector(2 downto 0);
signal s_out: std_logic_vector(1 downto 0);
 
begin
 
 --Connect DUT
  DUT: full_adder port map(a_in, s_out);
 
 process
 begin
  a_in <= "000";
  wait for 1 ns;
  
  a_in <= "001";
  wait for 1 ns;
  
  a_in <= "010";
  wait for 1 ns;
  
  a_in <= "011";
  wait for 1 ns;
  
  a_in <= "100";
  wait for 1 ns;
  
  a_in <= "101";
  wait for 1 ns;
  
  a_in <= "110";
  wait for 1 ns;
  
  a_in <= "111";
  wait for 1 ns;
   
  wait;
 end process;
end tb;