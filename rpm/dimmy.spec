Name:      dimmy


%{!?qtc_qmake:%define qtc_qmake %qmake}
%{!?qtc_qmake5:%define qtc_qmake5 %qmake5}
%{!?qtc_make:%define qtc_make make}
%{?qtc_builddir:%define _builddir %qtc_builddir}
Summary:    Dimmer screen
Version:    0.0.1
Release:    1
Group:      Qt/Qt
License:    WTFPL
URL:        https://github.com/kimmoli/dimmy
Source0:    %{name}-%{version}.tar.bz2
Requires:   sailfishsilica-qt5 >= 0.10.9
BuildRequires:  pkgconfig(sailfishapp) >= 1.0.2
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  desktop-file-utils

%description
Commandline tool to make screen dimmer

%prep
%setup -q -n %{name}-%{version}

%build

%qtc_qmake5  \
    VERSION=%{version}

%qtc_make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%qmake5_install

%files
%defattr(-,root,root,-)
%{_bindir}
%{_datadir}/%{name}
