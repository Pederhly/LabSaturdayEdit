clear
clc
% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%% helicopter specific settings
Joystick_gain_x = 1;
Joystick_gain_y = -1;
PORT=4;

%% Physical constants
g = 9.81;       % gravitational constant [m/s^2]
l_c = 0.40;     % distance elevation axis to counterweight [m]
l_h = 0.66;     % distance elevation axis to helicopter head [m]
l_p = 0.175;    % distance pitch axis to motor [m]
m_c = 1.92;     % Counterweight mass [kg]
m_p = 0.65;     % Motor mass [kg]

%% Calculated values

Vs_0 = 6;
k_f = g*(2*m_p*l_h-m_c*l_c)/(Vs_0*l_h);             % Motor constant [N/V]
k_1 = k_f/(2*m_p*l_p);                              % Calculated constant
k_2 = (k_f*l_h)/(m_c*l_c^2+2*m_p*l_h^2);            % Elevation acceleration gain (e double dot)
%k_3 = (k_f*l_h)/(m_c*l_c^2+2*m_p*(l_h^2+l_p^2));    % Yaw acceleration gain (lambda double dot)
k_3 = g*(m_c*l_c-2*m_p*l_h)/(m_c*l_c^2+2*m_p*(l_h^2+l_p^2));

%% Controller values
lambda_1 = -60;
lambda_2 = -3;
K_pp = (lambda_1*lambda_2)/k_1;     %Pitch proportional gain
K_pd = -(lambda_1+lambda_2)/k_1;    %Pitch derivative gain

%% Lab 2: Task 1 - Multivariable control matrices and Q_lqr & R_lqr
A = [0 1 0; 0 0 0; 0 0 0];
B = [0 0; 0 k_1; k_2 0];
C = [1 0 0; 0 0 1];
D = zeros(2);

Q_dig = [40 20 10];     %Pitch, Pitch rate, angle rate
R_dig = [0.5 1];        %vs, vd

Q = eye(3).*Q_dig;
R = eye(2).*R_dig;
[K,S,e] = lqr(A,B,Q,R);
F = (C*(B*K-A)^-1*B)^-1;


%% Lab 2: task 3 - Augmented control matrices
A_aug = [A zeros(3,2); -C zeros(2)];
B_aug = [B; zeros(2)];
C_aug = [C zeros(2)];
D_aug = D;
G_aug = [0 0; 0 0; 0 0; -1 0; 0 -1];

Q_aug_dig = [40 10 40 1 10];    %Pitch, Pitch rate, angle rate, pitch integral, elevation rate integral
R_aug_dig = [0.05 1];           %Vs Vd

Q_aug = eye(5).*Q_aug_dig;
R_aug = eye(2).*R_aug_dig;

[K_aug,S_aug,e_aug] = lqr(A_aug,B_aug,Q_aug,R_aug);
F_aug = (C*(B*K_aug(:,1:3)-A)^-1*B)^-1;

%% Lab 3: task 1 - Estimator
A_est = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 1 0; 0 0 0 0 0; k_3 0 0 0 0];
B_est = [0 0 0 k_2 0; 0 k_1 0 0 0]';
C_est = eye(5);
P_est = [-30 -30 -30 -30 -30]; %Poles of estimator

% lab 3 2-state estimator
%C_est = [0 0 1 0 0; 0 0 0 0 1];
%P_est = [-5 -10 -25 -10 -20];

L = place(A_est',C_est',P_est)';

%% Lab 4: Kalman filter

A_c = zeros(6); A_c(1,2) = 1; A_c(3,4) = 1; A_c(6,1) = k_3;
B_c = zeros(6,2); B_c(2,2) = k_1; B_c(4,1) = k_2;
C_c = [eye(5) zeros(5,1)]; C_c(5,5) = 0; C_c(5,6) = 1;
D_c = zeros(5,2);

ss_c = ss(A_c,B_c,C_c,D_c);
[ss_d,~] = c2d(ss_c, 0.002);

A_d = ss_d.A;
B_d = ss_d.B;
C_d = ss_d.C;
D_d = ss_d.D;

P_init_pred = zeros(6);
X_init_pred = zeros(6,1); X_init_pred(3,1) = -0.4189;

o = 0.0001;
Q_d = 1000*eye(6).*[o/2  %Pitch
                o   %Pitch rate
                o   %Elevation
                o/5   %Elevation rate
                o   %Travel
                o/2]';%Travel rate
            
%Q_d(2,4) = o/10;
%Q_d(4,2) = Q_d(2,4);
%R_d = eye(5);


%Measurement covariance matrix (experiamentally found by hovering at equilibrium point)
R_d = 1000*[ 0.0028    0.0035    0.0028   -0.0042    0.0013;
        0.0035    0.0308    0.0172   -0.0103   -0.0238;
        0.0028    0.0172    0.0123   -0.0071   -0.0098;
        -0.0042   -0.0103   -0.0071    0.0149    0.0040;
        0.0013   -0.0238   -0.0098    0.0040    0.0773];


