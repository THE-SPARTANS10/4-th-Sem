library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

--DUT Component
component parallel_adder is
port(
    Pa,Pb : in std_logic_vector(3 downto 0);
    Pcin : in std_logic;
    Ps : out std_logic_vector(3 downto 0);
    Pc : out std_logic);
end component;
 
signal Pa,Pb : std_logic_vector(3 downto 0);
signal Pcin : std_logic;
signal Ps : std_logic_vector(3 downto 0);
signal Pc : std_logic;
 
begin
 
 --Connect DUT
  DUT: parallel_adder port map(Pa, Pb, Pcin, Ps, Pc);
 
 process
 begin
  Pa <= "1000";
  Pb <= "0011";
  Pcin <= '1';
  wait for 1 ns;
  
  wait;
 end process;
end tb;