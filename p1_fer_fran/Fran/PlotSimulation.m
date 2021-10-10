function [result] = PlotSimulation(run_name,sim_name)
%Simulink.sdi.loadView('defaultsignalconfig.mldatx')
Simulink.sdi.setRunNamingRule(run_name+' <run_index> <model_name>');
result=sim(sim_name)
plot(result)
Simulink.sdi.view
%Simulink.sdi.loadView('defaultsignalconfig.mldatx');
end

